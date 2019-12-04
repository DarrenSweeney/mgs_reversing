param([String]$psyq_path4dot4, [String]$psyq_path4dot3)

$ErrorActionPreference = "Stop"

Push-Location $PSScriptRoot

$oldPathEnv = $Env:path 

Function psyq_setup($psyq_path)
{
    # Setup PSYQ env vars
    $Env:path = $oldPathEnv + ";" + $psyq_path
    $Env:PSYQ_PATH = $psyq_path
    # Setup PSYQ ini
    $psyq_path_without_bin = $psyq_path
    if ($psyq_path_without_bin.EndsWith("\bin\", "CurrentCultureIgnoreCase"))
    {
        $psyq_path_without_bin = $psyq_path_without_bin.Substring(0, $psyq_path_without_bin.Length - 5)
    }
    elseif ($psyq_path_without_bin.EndsWith("\bin", "CurrentCultureIgnoreCase"))
    {
        $psyq_path_without_bin = $psyq_path_without_bin.Substring(0, $psyq_path_without_bin.Length - 4)
    }

    $env:C_PLUS_INCLUDE_PATH = "$psyq_path_without_bin\include"
    $Env:c_include_path = "$psyq_path_without_bin\include"
    $env:PSX_PATH = $psyq_path

    (Get-Content $psyq_path\psyq.ini.template) | 
    Foreach-Object {$_ -replace '\$PSYQ_PATH',$psyq_path_without_bin}  | 
    Out-File $psyq_path\psyq.ini
}


function compile_c($fileName)
{
    $objName = $objName.replace(".C", "").replace(".c", "").replace("src\", "obj\")
  
    $parentFolder = Split-Path -Path $objName -Parent
    New-Item -ItemType directory -Path $parentFolder -ErrorAction SilentlyContinue | out-null

    ccpsx.exe -O2 -g -c -Wall "$fileName" "-o$objName.obj" -I  $PSScriptRoot\..\src
    if($LASTEXITCODE -eq 0)
    {
        Write-Host "Compiled $fileName"  -ForegroundColor "green"
    } 
    else 
    {
        Write-Error "Compilation failed for: ccpsx.exe -O2 -g -c -Wall $objName.c -o$objName.obj"
    }
}

#Remove-Item $PSScriptRoot\..\obj -Recurse -ErrorAction Ignore | out-null
New-Item -ItemType directory -Path $PSScriptRoot\..\obj -ErrorAction SilentlyContinue | out-null

# Most source compiles against psyq 4.4
psyq_setup($psyq_path4dot4)

# Compile all .C files with psyq 4.4
$cFiles = Get-ChildItem -Recurse ..\src\* -Include *.c | Select-Object -ExpandProperty FullName

foreach ($file in $cFiles)
{
    $objName = $file
    if ($objName.IndexOf("mts") -eq -1)
    {
        compile_c($objName)
    }
}

# MTS compiles against psyq 4.3 (compiler at least, libs are the same for now)
psyq_setup($psyq_path4dot3)

foreach ($file in $cFiles)
{
    $objName = $file
    if ($objName.IndexOf("mts") -ne -1)
    {
        compile_c($objName)
    }
}

#ccpsx.exe -O2 -c -Wall "$PSScriptRoot\..\src\mts_new.c" "-o$PSScriptRoot\..\obj\mts_new.obj"

# Compile all .S files
$sFiles =  Get-ChildItem -Recurse ..\asm\* -Include *.s | Select-Object -ExpandProperty FullName
foreach ($file in $sFiles)
{
	$fullObjName =  $file.replace(".S", ".obj").replace(".s", ".obj").replace("asm\", "obj\")
	$fullSName = $file
	
	$upToDate = $false

	if ([System.IO.File]::Exists("$fullObjName"))
	{
		$asmWriteTime = (get-item "$fullSName").LastWriteTime
		$objWriteTime = (get-item "$fullObjName").LastWriteTime
		$upToDate = $asmWriteTime -le $objWriteTime
		#Write-Host "$asmWriteTime $objWriteTime = $upToDate"
	}
	
	if ($upToDate -eq $false)
	{
		asmpsx.exe /l /q $fullSName,$fullObjName 
		if($LASTEXITCODE -eq 0)
		{
			Write-Host "Assembled $fullSName"  -ForegroundColor "green"
		} 
		else 
		{
			Write-Error "Assembling failed for asmpsx.exe /l /q $fullSName,$fullObjName"
		}
	}
}

# Run the linker
psylink.exe /c /n 4000 /q /gp .sdata /m "@$PSScriptRoot\linker_command_file.txt",$PSScriptRoot\..\obj\test2.cpe,$PSScriptRoot\..\obj\asm.sym,$PSScriptRoot\..\obj\asm.map
if($LASTEXITCODE -eq 0)
{
    Write-Host "Linked test2.cpe" -ForegroundColor "yellow"
} 
else 
{
    Write-Error "Linking failed $LASTEXITCODE"
}

# Convert CPE to an EXE
#cpe2x.exe test2.cpe
cpe2exe.exe /CJ ..\obj\test2.cpe | out-null

if($LASTEXITCODE -eq 0)
{
    Write-Host "..\obj\test2.cpe -> ..\obj\test2.exe" -ForegroundColor "yellow"
} 
else 
{
    Write-Error "Converting CPE to EXE failed"
}


if ([System.IO.File]::Exists(".\MDasm.exe"))
{
	.\MDasm.exe ..\SLPM_862.47 21344 21464 | Out-File "target.asm"
	.\MDasm.exe ..\obj\test2.exe 21344 21464 | Out-File "dump.asm"
}

# Validate the output is matching the OG binary hash
$actualValue = Get-FileHash -Path $PSScriptRoot\..\obj\test2.exe -Algorithm SHA256
if ($actualValue.Hash -eq "4b8252b65953a02021486406cfcdca1c7670d1d1a8f3cf6e750ef6e360dc3a2f")
{
    .\progress.ps1
    Write-Host OK $actualValue.Hash -ForegroundColor "green"
}
else
{
    Write-Host Binary is not matching $actualValue.Hash -ForegroundColor "red"
    exit 1
}

