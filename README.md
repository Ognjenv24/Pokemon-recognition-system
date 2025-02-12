# Prepoznavanje objekata na slici

## Projekat iz "Projektovanje elektronskih uređaja na sistemskom nivou"

**Mentor projekta:** Nebojša Pilipović  
**Autori projekta:**  
- Nikola Kovačić EE 77/2020  
- Ognjen Višnjić EE 217/2020  

## Sadržaj

1. [Uvod](#uvod)
2. [Specifikacija](#specifikacija)
   - [Učitavanje slike](#učitavanje-slike)
   - [Segmentacija boja](#segmentacija-boja)
   - [Morfološka operacija](#morfološka-operacija)
   - [Detekcija kontura](#detekcija-kontura)
   - [Filtriranje i označavanje objekata](#filtriranje-i-označavanje-objekata)
   - [Prikaz rezultata](#prikaz-rezultata)
3. [Profiling](#profiling)
   - [Valgrind analiza](#valgrind-analiza)
   - [Optimizacija](#optimizacija)
4. [Virtualna platforma](#virtualna-platforma)
   - [CPU](#cpu)
   - [Interconnect](#interconnect)
   - [BRAM](#bram)
   - [IP modul](#ip-modul)
   - [Opis rada virtualne platforme](#opis-rada-virtualne-platforme)
5. [Bitska analiza](#bitska-analiza)
6. [HLS sinteza](#hls-sinteza)
7. [Zaključak](#zaključak)
8. [Literatura](#literatura)

---

## Uvod

Ovaj projekat se fokusira na razvoj softverskog rešenja za identifikaciju, brojanje i označavanje objekata na osnovu boje na digitalnim slikama. Specifično, program koristi algoritme segmentacije zasnovane na boji, morfološke operacije i detekciju kontura za efikasno prepoznavanje i označavanje objekata.

Glavni cilj projekta je prepoznavanje **10 različitih Pokemon karaktera**, gde je svaki definisan jedinstvenim spektrom boja.

Program je razvijen u **C++** koristeći **OpenCV biblioteku**.

## Specifikacija

### Učitavanje slike

Slika se učitava pomoću `cv::imread()`, gde se koristi **cv::IMREAD_COLOR** za čitanje slike u boji.

### Segmentacija boja

Koristi se funkcija `cv::inRange()` za kreiranje **binarne maske** na osnovu unapred definisanih opsega boja.

### Morfološka operacija

Primenjuju se **morfološke operacije** kao što su **dilatacija** i **erozija** pomoću `cv::morphologyEx()` kako bi se poboljšao kvalitet segmentacije.

### Detekcija kontura

Konture objekata se detektuju pomoću `cv::findContours()`, pri čemu se koriste **cv::RETR_EXTERNAL** i **cv::CHAIN_APPROX_SIMPLE**.

### Filtriranje i označavanje objekata

- Za filtriranje kontura koriste se `cv::contourArea()` i `cv::boundingRect()`.
- Označavanje objekata vrši se pomoću `cv::rectangle()` i `cv::putText()`.

### Prikaz rezultata

Konačni rezultat se prikazuje korišćenjem `cv::imshow()`.

## Profiling

### Valgrind analiza

Analiza performansi vršena je pomoću **Valgrind Callgrind alata**.

Najzahtevnije funkcije:
- `cv::inRange()` - **26.99%** CPU vremena
- `cv::morphologyEx()` - **19.90%** CPU vremena
- `cv::findContours()` - **8.94%** CPU vremena

### Optimizacija

Radi poboljšanja performansi:
- Implementirana je ručna segmentacija boja umesto `cv::inRange()`
- Korišćeni su ručni morfološki algoritmi umesto `cv::morphologyEx()`
- Optimizovan algoritam za detekciju kontura

## Virtualna platforma

### CPU
- Kontroliše tok podataka i upravlja obrada slike.

### Interconnect
- Usmerava podatke između CPU-a, BRAM-a i IP modula.

### BRAM
- Memorija sistema u kojoj se skladište slike.

### IP modul
- Izvodi obradu slike koristeći detekciju kontura i filtriranje objekata.

### Opis rada virtualne platforme
- Slika se učitava u **BRAM**
- Obrada slike se vrši u **IP modulu**
- Prikazuju se prepoznati objekti

## Bitska analiza

Rađena je analiza potrošnje memorije i bitova u sistemu:
- Pikseli slike predstavljeni sa **3 x 8-bitne vrednosti** (RGB)
- Adresni signali **64-bitni**
- Brojači objekata **16-bitni**

## HLS sinteza

Sinteza rađena u **Vitis HLS** alatu:
- Vreme kašnjenja IP bloka: **8.5 ns**
- Vreme kašnjenja BRAM-a: **5 ns**
- Obrada jedne slike: **93,500 ps**
- Sistem može obraditi **10 slika u sekundi**

## Zaključak

Projekat je uspešno demonstrirao:
- Preciznu segmentaciju boja
- Efikasnu detekciju i brojanje objekata
- Optimizovanu implementaciju u C++
- Virtualnu platformu za testiranje

Ograničenja:
- Sistem može prepoznati samo **10 unapred definisanih Pokemona**
- Osetljivost na osvetljenje može uticati na tačnost

## Literatura

1. [Contour Detection and Hierarchical Image Segmentation](https://www2.eecs.berkeley.edu/Research/Projects/CS/vision/grouping/papers/amfm_pami2010.pdf)
2. [OpenCV - Open Computer Vision Library](https://opencv.org/)
3. [SystemC](https://systemc.org/overview/systemc/)
4. [Vitis HLS Tutorials](https://xilinx.github.io/Vitis-Tutorials/2021-1/build/html/docs/Getting_Started/Vitis_HLS/Getting_Started_Vitis_HLS.html)
5. [Virtualna platforma](https://www.elektronika.ftn.uns.ac.rs/projektovanje-elektronskih-uredjaja-na-sistemskom-nivou/wp-content/uploads/sites/117/2018/03/v12.pdf)

