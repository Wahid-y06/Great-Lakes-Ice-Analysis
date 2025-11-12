# Great Lakes Ice Coverage Analysis (2021–2024)

This project analyzes multi-year ice coverage trends across the Great Lakes using a custom C program.  
It processes cleaned datasets from **2021–2024**, computes averages, identifies extreme ice coverage events,  
and generates `.dat` files for visualization using **Gnuplot**.

This project was developed for **CPS188 – Computer Science I** at **Toronto Metropolitan University (TMU)**.

---

## 📊 Project Overview

The program performs detailed analysis on ice coverage across the major Great Lakes:

- **Lake Superior**
- **Lake Michigan**
- **Lake Huron**
- **Lake Erie**
- **Lake Ontario**
- **Lake St. Clair**
- **Great Lakes Total**

Using cleaned CSV datasets, the program calculates:

### ✔️ Yearly Averages  
For each lake across the years:
- 2021  
- 2022  
- 2023  
- 2024  

### ✔️ Minimum & Maximum Ice Coverage  
- Finds which lake had the **lowest** average  
- Finds which lake had the **highest** average  

### ✔️ Highest Recorded Ice Percentages  
- Detects the highest single-day ice percentage  
- Prints all days that tied for the highest record  

### ✔️ Gnuplot Data Generation  
Outputs `.dat` files for plotting:
- `superior.dat`  
- `michigan.dat`  
- `huron.dat`  
- `erie.dat`  
- `ontario.dat`  
- `stclair.dat`

These can be graphed using Gnuplot scripts in the `plots/` folder.

---

## 📁 Project Structure

```bash
Great-Lakes-Ice-Analysis/
│
├── TeamProject.c                  # Main C analysis program
│
├── cleaned_termproject.csv        # Cleaned dataset (2023–2024)
├── cleaned_termprojectc.csv
├── 2021-2022.csv
├── 2021-2022gnu.csv
├── 2022-2023.csv
├── 2022-2023gnu.csv
├── 2023-2024gnu.csv
│
├── plots/                         # Gnuplot scripts & images
│   ├── 6lakesplot.gp
│   ├── Concentrationplot.gp
│   └── (screenshots if added)
│
└── README.md
