

extern void DG_ClearTextureRecs_8001D808(void);
extern void DG_ResetResidentTexture_8001DBEC(void);

void DG_TextureCacheInit_8001F25C(void)
{
    DG_ClearTextureRecs_8001D808();
    DG_ResetResidentTexture_8001DBEC();
}