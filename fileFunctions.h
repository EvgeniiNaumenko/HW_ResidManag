#pragma once

void writeToFile(Apartment*& ap, int apSize,Sitizen*& sit, int sitSize)
{
    const char dataPath[] = "apartmentData.dat";
    const char keyDataPath[] = "keyData";
    FILE* file;
    if (fopen_s(&file, dataPath, "wb") == 0)
    {
        for (int i = 0; i < apSize; i++)
        {
            fwrite(&ap[i], sizeof(Apartment), 1, file);
        }
        for (int i = 0; i < sitSize; i++)
        {
            fwrite(&sit[i], sizeof(Sitizen), 1, file);
        }

    }
    fclose(file);
    if (fopen_s(&file, keyDataPath, "wb") == 0)
    {
        fwrite(&apSize, sizeof(int), 1, file);
        fwrite(&sitSize, sizeof(int), 1, file);
    }
    fclose(file);
}
void readFromFile(Apartment*& ap, int& apSize,Sitizen*& sit, int& sitSize)
{
    const char dataPath[] = "apartmentData.dat";
    const char keyDataPath[] = "keyData";
    FILE* file;
    if (fopen_s(&file, keyDataPath, "rb") == 0)
    {

        fread(&apSize, sizeof(int), 1, file);
        fread(&sitSize, sizeof(int), 1, file);
    }
    fclose(file);

    if (fopen_s(&file, dataPath, "rb") == 0)
    {
        Apartment* newApp = new Apartment[apSize];
        for (int i = 0; i < apSize; i++)
        {
            fread(&newApp[i], sizeof(Apartment), 1, file);   
        }
        delete[] ap;
        ap = newApp;

        Sitizen* newSit = new Sitizen[apSize];
        for (int i = 0; i < sitSize; i++)
        {
            fread(&newSit[i], sizeof(Sitizen), 1, file);
        }
        delete[] sit;
        sit = newSit;
    }
    fclose(file);

}