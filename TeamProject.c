//CPS188 group 18
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 500 

//data from cleaned_termproject.csv
void process2023_2024(void) {
    typedef struct {
        int year, day;
        double sup, mich, huron, erie, ont, st_clr, gl_total;
    } IceData;
    typedef struct {
        int year, day;
    } Record;
    
    FILE *file = fopen("cleaned_termprojectc.csv", "r");
    if (!file) {
        perror("Error opening cleaned_termproject.csv");
        return;
    }
    
    IceData data[MAX_ROWS];
    int count = 0;
    char header[200];
    if (fgets(header, sizeof(header), file) == NULL) {
        printf("Error reading header from cleaned_termproject.csv.\n");
        fclose(file);
        return;
    }
    
    while (fscanf(file, "%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                  &data[count].year, &data[count].day,
                  &data[count].sup, &data[count].mich, &data[count].huron,
                  &data[count].erie, &data[count].ont,
                  &data[count].st_clr, &data[count].gl_total) == 9) {
        count++;
        if (count >= MAX_ROWS) break;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No valid data found in cleaned_termproject.csv.\n");
        return;
    }
    
    // yearly averages for 2023 and 2024
    double sum_2023[7] = {0}, sum_2024[7] = {0};
    int count_2023 = 0, count_2024 = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == 2023) {
            sum_2023[0] += data[i].sup;
            sum_2023[1] += data[i].mich;
            sum_2023[2] += data[i].huron;
            sum_2023[3] += data[i].erie;
            sum_2023[4] += data[i].ont;
            sum_2023[5] += data[i].st_clr;
            sum_2023[6] += data[i].gl_total;
            count_2023++;
        } else if (data[i].year == 2024) {
            sum_2024[0] += data[i].sup;
            sum_2024[1] += data[i].mich;
            sum_2024[2] += data[i].huron;
            sum_2024[3] += data[i].erie;
            sum_2024[4] += data[i].ont;
            sum_2024[5] += data[i].st_clr;
            sum_2024[6] += data[i].gl_total;
            count_2024++;
        }
    }
    
    printf("=== 2023-2024 Averages (from cleaned_termproject.csv) ===\n");
    if (count_2023 > 0) {
        printf("2023: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2023[0]/count_2023, sum_2023[1]/count_2023, sum_2023[2]/count_2023,
               sum_2023[3]/count_2023, sum_2023[4]/count_2023, sum_2023[5]/count_2023,
               sum_2023[6]/count_2023);
    }
    if (count_2024 > 0) {
        printf("2024: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2024[0]/count_2024, sum_2024[1]/count_2024, sum_2024[2]/count_2024,
               sum_2024[3]/count_2024, sum_2024[4]/count_2024, sum_2024[5]/count_2024,
               sum_2024[6]/count_2024);
    }
    
    // min Max averages per Lake
    double avg_2023[6], avg_2024[6];
    for (int i = 0; i < 6; i++) {
        avg_2023[i] = sum_2023[i] / count_2023;
        avg_2024[i] = sum_2024[i] / count_2024;
    }
    char *lake_names[] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St_Clair"};
    double min23 = 1e9, max23 = -1e9, min24 = 1e9, max24 = -1e9;
    int min_index_23 = -1, max_index_23 = -1, min_index_24 = -1, max_index_24 = -1;
    for (int i = 0; i < 6; i++) {
        if (avg_2023[i] < min23) { min23 = avg_2023[i]; min_index_23 = i; }
        if (avg_2023[i] > max23) { max23 = avg_2023[i]; max_index_23 = i; }
        if (avg_2024[i] < min24) { min24 = avg_2024[i]; min_index_24 = i; }
        if (avg_2024[i] > max24) { max24 = avg_2024[i]; max_index_24 = i; }
    }
    printf("2023: Min = %.2f (%s), Max = %.2f (%s)\n",
           min23, lake_names[min_index_23], max23, lake_names[max_index_23]);
    printf("2024: Min = %.2f (%s), Max = %.2f (%s)\n",
           min24, lake_names[min_index_24], max24, lake_names[max_index_24]);
    
    // --- Highest Ice Percentages by Lake ---
    double max_lake[6] = {0.0};
    int max_count_lake[6] = {0};
    Record max_lake_records[6][MAX_ROWS];
    for (int i = 0; i < count; i++) {
        double lake_vals[6] = { data[i].sup, data[i].mich, data[i].huron,
                                data[i].erie, data[i].ont, data[i].st_clr };
        for (int j = 0; j < 6; j++) {
            if (lake_vals[j] > max_lake[j]) {
                max_lake[j] = lake_vals[j];
                max_count_lake[j] = 1;
                max_lake_records[j][0].year = data[i].year;
                max_lake_records[j][0].day = data[i].day;
            } else if (lake_vals[j] == max_lake[j]) {
                max_lake_records[j][max_count_lake[j]].year = data[i].year;
                max_lake_records[j][max_count_lake[j]].day = data[i].day;
                max_count_lake[j]++;
            }
        }
    }
    printf("\n=== Highest Ice Percentages by Lake (2023-2024) ===\n");
    for (int i = 0; i < 6; i++) {
        printf("%s: %.2f%%\n", lake_names[i], max_lake[i]);
        for (int j = 0; j < max_count_lake[i]; j++) {
            printf("  Day: %d, Year: %d\n", max_lake_records[i][j].day, max_lake_records[i][j].year);
        }
    }
    
    // -highest percentage 
    double max_ice = 0.0;
    int max_count = 0;
    struct {
        int year, day;
        char lake[10];
    } max_records[MAX_ROWS];
    
    for (int i = 0; i < count; i++) {
        struct { double value; char name[10]; } lakes[] = {
            { data[i].sup, "Superior" },
            { data[i].mich, "Michigan" },
            { data[i].huron, "Huron" },
            { data[i].erie, "Erie" },
            { data[i].ont, "Ontario" },
            { data[i].st_clr, "St_Clair" }
        };
        for (int j = 0; j < 6; j++) {
            if (lakes[j].value > max_ice) {
                max_ice = lakes[j].value;
                max_count = 0;
                max_records[max_count].year = data[i].year;
                max_records[max_count].day = data[i].day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count = 1;
            } else if (lakes[j].value == max_ice) {
                max_records[max_count].year = data[i].year;
                max_records[max_count].day = data[i].day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count++;
            }
        }
    }
    if (max_ice > 0.0) {
        printf("\nOverall Highest Ice Percentage (2023-2024): %.2f%%\n", max_ice);
        for (int i = 0; i < max_count; i++) {
            printf("Day: %d, Year: %d, Lake: %s\n",
                   max_records[i].day, max_records[i].year, max_records[i].lake);
        }
    } else {
        printf("\nNo ice data available to determine the overall highest percentage (2023-2024).\n");
    }
    
    // Q4:
    FILE *lake_files[6];
    char *lake_file_names[] = { "superior.dat", "michigan.dat", "huron.dat",
                                 "erie.dat", "ontario.dat", "stclair.dat" };
    for (int i = 0; i < 6; i++) {
        lake_files[i] = fopen(lake_file_names[i], "w");
        if (!lake_files[i]) {
            printf("Error opening %s for writing.\n", lake_file_names[i]);
            return;
        }
    }
    for (int i = 0; i < count; i++) {
        fprintf(lake_files[0], "%d %.2f\n", data[i].day, data[i].sup);
        fprintf(lake_files[1], "%d %.2f\n", data[i].day, data[i].mich);
        fprintf(lake_files[2], "%d %.2f\n", data[i].day, data[i].huron);
        fprintf(lake_files[3], "%d %.2f\n", data[i].day, data[i].erie);
        fprintf(lake_files[4], "%d %.2f\n", data[i].day, data[i].ont);
        fprintf(lake_files[5], "%d %.2f\n", data[i].day, data[i].st_clr);
    }
    for (int i = 0; i < 6; i++) {
        fclose(lake_files[i]);
    }
    
    printf("\nProcessed 2023-2024 data from cleaned_termproject.csv.\n\n");
}

// data from 2021-2022.csv
void process2021_2022(void) {
    typedef struct {
        int year;
        double sup, mich, huron, erie, ont, st_clr, gl_total;
    } IceData;
    
    FILE *file = fopen("2021-2022.csv", "r");
    if (!file) {
        perror("Error opening 2021-2022.csv");
        return;
    }
    IceData data[MAX_ROWS];
    int count = 0;
    char header[200];
    if (fgets(header, sizeof(header), file) == NULL) {
        printf("Error reading header from 2021-2022.csv.\n");
        fclose(file);
        return;
    }
    while (fscanf(file, "%d,%*d,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                  &data[count].year, &data[count].sup, &data[count].mich,
                  &data[count].huron, &data[count].erie, &data[count].ont,
                  &data[count].st_clr, &data[count].gl_total) == 8) {
        count++;
        if (count >= MAX_ROWS) break;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No valid data found in 2021-2022.csv.\n");
        return;
    }
    
    // yearly avg 21/22
    double sum_2021[7] = {0}, sum_2022[7] = {0};
    int count_2021 = 0, count_2022 = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == 2021) {
            sum_2021[0] += data[i].sup;
            sum_2021[1] += data[i].mich;
            sum_2021[2] += data[i].huron;
            sum_2021[3] += data[i].erie;
            sum_2021[4] += data[i].ont;
            sum_2021[5] += data[i].st_clr;
            sum_2021[6] += data[i].gl_total;
            count_2021++;
        } else if (data[i].year == 2022) {
            sum_2022[0] += data[i].sup;
            sum_2022[1] += data[i].mich;
            sum_2022[2] += data[i].huron;
            sum_2022[3] += data[i].erie;
            sum_2022[4] += data[i].ont;
            sum_2022[5] += data[i].st_clr;
            sum_2022[6] += data[i].gl_total;
            count_2022++;
        }
    }
    
    printf("=== 2021-2022 Averages (from 2021-2022.csv) ===\n");
    if (count_2021 > 0) {
        printf("2021: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2021[0]/count_2021, sum_2021[1]/count_2021, sum_2021[2]/count_2021,
               sum_2021[3]/count_2021, sum_2021[4]/count_2021, sum_2021[5]/count_2021,
               sum_2021[6]/count_2021);
    } else {
        printf("No data available for 2021.\n");
    }
    if (count_2022 > 0) {
        printf("2022: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2022[0]/count_2022, sum_2022[1]/count_2022, sum_2022[2]/count_2022,
               sum_2022[3]/count_2022, sum_2022[4]/count_2022, sum_2022[5]/count_2022,
               sum_2022[6]/count_2022);
    } else {
        printf("No data available for 2022.\n");
    }
    
    // high ice concentration 2122
    double max_ice = 0.0;
    int max_count = 0;
    typedef struct {
        int year, day;
        char lake[10];
    } MaxRecord;
    MaxRecord max_records[MAX_ROWS];
    
    // 
    file = fopen("2021-2022.csv", "r");
    if (!file) {
        perror("Error reopening 2021-2022.csv");
        return;
    }
    fgets(header, sizeof(header), file); // skip header
    int temp_year, temp_day;
    double temp_sup, temp_mich, temp_huron, temp_erie, temp_ont, temp_st_clr, temp_gl_total;
    while (fscanf(file, "%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                  &temp_year, &temp_day, &temp_sup, &temp_mich, &temp_huron,
                  &temp_erie, &temp_ont, &temp_st_clr, &temp_gl_total) == 9) {
        struct { double value; char name[10]; } lakes[] = {
            { temp_sup, "Superior" },
            { temp_mich, "Michigan" },
            { temp_huron, "Huron" },
            { temp_erie, "Erie" },
            { temp_ont, "Ontario" },
            { temp_st_clr, "St_Clair" }
        };
        for (int j = 0; j < 6; j++) {
            if (lakes[j].value > max_ice) {
                max_ice = lakes[j].value;
                max_count = 0;
                max_records[max_count].year = temp_year;
                max_records[max_count].day = temp_day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count = 1;
            } else if (lakes[j].value == max_ice) {
                max_records[max_count].year = temp_year;
                max_records[max_count].day = temp_day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count++;
            }
        }
    }
    fclose(file);
    
    if (max_ice > 0.0) {
        printf("\nHighest Ice Percentage Recorded (2021-2022): %.2f%%\n", max_ice);
        for (int i = 0; i < max_count; i++) {
            printf("Day: %d, Year: %d, Lake: %s\n",
                   max_records[i].day, max_records[i].year, max_records[i].lake);
        }
    } else {
        printf("\nNo ice data available to determine the highest ice percentage (2021-2022).\n");
    }
    
    printf("\nProcessed 2021-2022 data from 2021-2022.csv.\n\n");
}

// data from 2022-2023.csv
void process2022_2023(void) {
    // Local structure without day field (for averages)
    typedef struct {
        int year;
        double sup, mich, huron, erie, ont, st_clr, gl_total;
    } IceData;
    
    FILE *file = fopen("2022-2023.csv", "r");
    if (!file) {
        perror("Error opening 2022-2023.csv");
        return;
    }
    IceData data[MAX_ROWS];
    int count = 0;
    char header[200];
    if (fgets(header, sizeof(header), file) == NULL) {
        printf("Error reading header from 2022-2023.csv.\n");
        fclose(file);
        return;
    }
    while (fscanf(file, "%d,%*d,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                  &data[count].year, &data[count].sup, &data[count].mich,
                  &data[count].huron, &data[count].erie, &data[count].ont,
                  &data[count].st_clr, &data[count].gl_total) == 8) {
        count++;
        if (count >= MAX_ROWS) break;
    }
    fclose(file);
    
    if (count == 0) {
        printf("No valid data found in 2022-2023.csv.\n");
        return;
    }
    
    // yearly avg 2223
    double sum_2022[7] = {0}, sum_2023[7] = {0};
    int count_2022 = 0, count_2023 = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == 2022) {
            sum_2022[0] += data[i].sup;
            sum_2022[1] += data[i].mich;
            sum_2022[2] += data[i].huron;
            sum_2022[3] += data[i].erie;
            sum_2022[4] += data[i].ont;
            sum_2022[5] += data[i].st_clr;
            sum_2022[6] += data[i].gl_total;
            count_2022++;
        } else if (data[i].year == 2023) {
            sum_2023[0] += data[i].sup;
            sum_2023[1] += data[i].mich;
            sum_2023[2] += data[i].huron;
            sum_2023[3] += data[i].erie;
            sum_2023[4] += data[i].ont;
            sum_2023[5] += data[i].st_clr;
            sum_2023[6] += data[i].gl_total;
            count_2023++;
        }
    }
    
    printf("=== 2022-2023 Averages (from 2022-2023.csv) ===\n");
    if (count_2022 > 0) {
        printf("2022: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2022[0]/count_2022, sum_2022[1]/count_2022, sum_2022[2]/count_2022,
               sum_2022[3]/count_2022, sum_2022[4]/count_2022, sum_2022[5]/count_2022,
               sum_2022[6]/count_2022);
    } else {
        printf("No data available for 2022 in 2022-2023.csv.\n");
    }
    if (count_2023 > 0) {
        printf("2023: Sup=%.4f, Mich=%.4f, Huron=%.4f, Erie=%.4f, Ont=%.4f, St_Clr=%.4f, GL_Total=%.4f\n",
               sum_2023[0]/count_2023, sum_2023[1]/count_2023, sum_2023[2]/count_2023,
               sum_2023[3]/count_2023, sum_2023[4]/count_2023, sum_2023[5]/count_2023,
               sum_2023[6]/count_2023);
    } else {
        printf("No data available for 2023 in 2022-2023.csv.\n");
    }
    
    // high ice concentration 2223
    double max_ice = 0.0;
    int max_count = 0;
    typedef struct {
        int year, day;
        char lake[10];
    } MaxRecord;
    MaxRecord max_records[MAX_ROWS];
    
    file = fopen("2022-2023.csv", "r");
    if (!file) {
        perror("Error reopening 2022-2023.csv");
        return;
    }
    fgets(header, sizeof(header), file); // skip header
    int temp_year, temp_day;
    double temp_sup, temp_mich, temp_huron, temp_erie, temp_ont, temp_st_clr, temp_gl_total;
    while (fscanf(file, "%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                  &temp_year, &temp_day, &temp_sup, &temp_mich, &temp_huron,
                  &temp_erie, &temp_ont, &temp_st_clr, &temp_gl_total) == 9) {
        struct { double value; char name[10]; } lakes[] = {
            { temp_sup, "Superior" },
            { temp_mich, "Michigan" },
            { temp_huron, "Huron" },
            { temp_erie, "Erie" },
            { temp_ont, "Ontario" },
            { temp_st_clr, "St_Clair" }
        };
        for (int j = 0; j < 6; j++) {
            if (lakes[j].value > max_ice) {
                max_ice = lakes[j].value;
                max_count = 0;
                max_records[max_count].year = temp_year;
                max_records[max_count].day = temp_day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count = 1;
            } else if (lakes[j].value == max_ice) {
                max_records[max_count].year = temp_year;
                max_records[max_count].day = temp_day;
                snprintf(max_records[max_count].lake, sizeof(max_records[max_count].lake), "%s", lakes[j].name);
                max_count++;
            }
        }
    }
    fclose(file);
    
    if (max_ice > 0.0) {
        printf("\nHighest Ice Percentage Recorded (2022-2023): %.2f%%\n", max_ice);
        for (int i = 0; i < max_count; i++) {
            printf("Day: %d, Year: %d, Lake: %s\n",
                   max_records[i].day, max_records[i].year, max_records[i].lake);
        }
    } else {
        printf("\nNo ice data available to determine the highest ice percentage (2022-2023).\n");
    }
    
    printf("\nProcessed 2022-2023 data from 2022-2023.csv.\n\n");
}

int main(void) {
    // 2023-2024 data 
    process2023_2024();
    
    // 2. 2021-2022 data 
    process2021_2022();
    
    // 3. 2022-2023 data
    process2022_2023();
    
    return 0;
}
