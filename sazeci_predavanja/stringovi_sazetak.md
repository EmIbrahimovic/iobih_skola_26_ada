# Stringovi — Sažetak Predavanja
**Datum:** 29. mart 2026 | **Trajanje:** 1h 58m 48s  
**Predavač:** Edukacijska grupa Ada  
**Publika:** Talentovani učenici osnovne škole, početnici u programiranju

---

## 1. Teme i vremenski raspored

### `char` i ASCII tabela — cca. 0:00–15:00 (15 min)
- Ponavljanje tipa `char`: jedan karakter, jednostruki navodnici
- Razlika između validnog (`'A'`, `'7'`, `' '`) i nevalidnog (`"AB"`) `char`-a
- Ključna činjenica: svaki `char` se u memoriji čuva kao **broj**
- Kastovanje `char` → `int` da se vidi numerička vrijednost
- **ASCII tabela** — mapiranje karaktera u brojeve:
  - `'A'` = 65, `'a'` = 97, `'0'` = 48
  - Sva mala slova su uzastopna, sva velika su uzastopna, cifre su uzastopne
- Aritmetika na karakterima: `'a' + 1 = 'b'`, kastovanje nazad u `char`
- Kratka napomena o **Unicodu** (za `č`, `ć`, `š` itd.) i zašto se na takmičenjima koristi ASCII

### Zadaci sa `char`-ovima — cca. 15:00–43:36 (28 min)
- Tri zadatka urađena jedan za drugim (detalji u sekciji 2)
- Studenti su slali rješenja, predavač ih pregledao i komentarisao uživo

### Uvod u stringove — cca. 43:36–59:00 (15 min)
- Definicija: string = niz karaktera, dvostruki navodnici
- Razlika `char` (jedan znak) vs. `string` (niz znakova)
- `#include <string>` (ili automatski uz `<iostream>`)
- Ključne operacije:
  - `.length()` / `.size()` — dužina stringa
  - `niz[i]` — pristup pojedinačnom karakteru (vraća `char`)
  - Kastovanje karaktera iz stringa u `int`
  - Konkatenacija stringova operatorom `+`
  - Prolazak for petljom (klasičan i range-based)
- Unos stringa:
  - `cin >>` — prima samo jednu riječ (staje na razmaku)
  - `getline(cin, tekst)` — prima cijelu liniju sa razmacima

### Pauza — cca. 59:00–1:16:20 (17 min)
- Predavač iskoristio pauzu i za privatnu provjeru zadaće jednog studenta

### Zadaci sa stringovima — cca. 1:16:20–1:58:48 (42 min)
- Tri zadatka urađena jedan za drugim (detalji u sekciji 2)
- Zadnji zadatak (Cezarova šifra) ostavljen kao djelimično nedovršen zbog vremena

---

## 2. Primjeri i zadaci

### Primjer — Aritmetika na `char`-ovima (cca. 0:00–15:00)
Predavač je uživo demonstrirao:
```cpp
char c = 'a';
cout << (int)c;        // ispisuje 97
cout << (char)(c + 1); // ispisuje 'b'
```
i objasnio zašto ovo funkcioniše putem ASCII tabele (guglano i pokazano uživo).

---

### Zadatak 1 — Ispis abecede petljom (cca. 15:00–25:00)
**Cilj:** Ispisati sva mala, pa sva velika slova abecede — bez ručnog navođenja, koristeći ASCII.
```cpp
for (char slovo = 'a'; slovo <= 'z'; slovo++) cout << slovo;
for (char slovo = 'A'; slovo <= 'Z'; slovo++) cout << slovo;
```
Studenti su brzo poslali rješenja. Predavač je pokazao rješenje i похvalио grupu.

---

### Zadatak 2 — Konverzija malo ↔ veliko slovo (cca. 25:00–36:00)
**Cilj:** Unijeti karakter — ako je malo ispisati kao veliko i obrnuto.  
**Ključni koncept:** Razlika između ASCII vrijednosti malih i velikih slova je uvijek **32**.
```cpp
if (slovo >= 'a' && slovo <= 'z')
    cout << (char)(slovo - ('a' - 'A')); // malo → veliko
else if (slovo >= 'A' && slovo <= 'Z')
    cout << (char)(slovo + ('a' - 'A')); // veliko → malo
```
Napomenuto da postoje ugrađene funkcije za ovo, ali da ih zasad ne koriste.

---

### Zadatak 3 — Klasifikacija karaktera (cca. 36:00–43:36)
**Cilj:** Unijeti karakter i ispisati je li `slovo`, `broj` ili `specijalni znak`.
```cpp
if ((karakter >= 'a' && karakter <= 'z') || (karakter >= 'A' && karakter <= 'Z'))
    cout << "slovo";
else if (karakter >= '0' && karakter <= '9')
    cout << "broj";
else
    cout << "specijalni znak";
```
Napomenuto: `cin >>` za `char` prima samo jedan karakter čak i ako se unese više.

---

### Zadatak 4 — String unazad (cca. 1:16:20–1:22:00)
**Cilj:** Učitati string i ispisati ga u obrnutom redoslijedu.
```cpp
for (int i = rijec.length() - 1; i >= 0; i--)
    cout << rijec[i];
```
Opisano kao "zagrijavanje" za stringove — studenti su ga brzo riješili.

---

### Zadatak 5 — Provjera palindroma (cca. 1:22:00–1:38:00)
**Cilj:** Provjeriti je li unesena rečenica palindrom, **ignorirajući razmake**.  
**Primjeri:** `"race car"` ✓, `"anna"` ✓, `"laurel"` ✗

**Pristup u dva koraka:**
1. Izgraditi novi string bez razmaka
2. Porediti karakter s početka sa odgovarajućim s kraja

```cpp
// Korak 1
string tekstBezSpisa = "";
for (int i = 0; i < tekst.length(); i++)
    if (tekst[i] != ' ') tekstBezSpisa += tekst[i];

// Korak 2
bool jePalindrom = true;
for (int i = 0; i < tekstBezSpisa.length(); i++)
    if (tekstBezSpisa[i] != tekstBezSpisa[tekstBezSpisa.length() - 1 - i])
        { jePalindrom = false; break; }
```

Ovaj zadatak je izazvao više diskusije — predavač je pregledao više različitih pristupa studenata i naglasio potrebu za `getline` (jer rečenica ima razmake).

---

### Zadatak 6 — Cezarova šifra (cca. 1:38:00–1:58:48)
**Cilj:** Unijeti string i broj `k`, pomjeriti svako slovo za `k` mjesta uz wraparound. Razmaci i specijalni znakovi se ne mijenjaju.  
**Primjer:** `"hello"` + `k=3` → `"khoor"`; `z + 3 = c`

**Ključni koncepti:**
- Modulo (`%`) za ciklično ponašanje
- Pretvaranje slova u redni broj u abecedi, pomicanje, pretvaranje nazad

```cpp
int redniBroj = c - 'a';                    // pozicija u abecedi (0-25)
int noviRedniBroj = (redniBroj + k) % 26;   // wraparound
cout << (char)(noviRedniBroj + 'a');         // nazad u char
```

Radi odvojeno za mala i velika slova. Zadatak nije stigao biti dovršen od svih — ostavljen je otvorenim. Predavač ga je demonstrirao pred kraj časa.

---

## 3. Angažovanje studenata i interakcija

### Stil predavanja
Predavač je koristio isključivo **live coding** — pisao i pokretao kod uživo pred studentima, namjerno uključujući greške koje je potom ispravljao. Zadaci su davani jedan po jedan, studenti su slali rješenja putem chata, a predavač ih je pregledao i komentarisao pred cijelom grupom. Ton je bio neformalan i podsticajan.

### Odziv studenata
Studenti su bili **aktivno angažovani** — brzo su slali rješenja i postavljali relevantna pitanja. Primjetno je da razumiju gradivo i da ga ne prate pasivno.

Aktivniji učesnici:
- **Hamza Kalajdžija** — postavio pitanje o unosu broja i slova istovremeno u `char`; pitao o zadaći s prethodnog predavanja
- **Vanja Arsenovski** — predložio alternativno rješenje za palindrom; naglasio potrebu za `getline`
- **Alan Kay** — pitao o razlici između jednostrukih i dvostrukih navodnika
- **Kosta Car** — postavljao pitanja o tipu stringa i kompatibilnosti
- **Više učesnika** — prijavljivali prisutnost, odgovarali na pitanja predavača

### Procjena vremena interakcije

| Vrsta interakcije | Trajanje (approx.) |
|---|---|
| Provjera prisutnosti / tehničke napomene | ~5 min |
| Pitanja i odgovori tokom objašnjavanja | ~15 min |
| Pregled i komentarisanje rješenja studenata | ~20 min |
| Diskusija o zadaći s prethodnog predavanja | ~7 min |
| **Ukupno** | **~47 min (~40% časa)** |

### Opšta napomena
Za učenike koji tek uče programiranje, nivo razumijevanja je iznenađujuće visok. Pitanja koja postavljaju su suštinska i pokazuju da aktivno razmišljaju o gradivu, ne samo da kopiraju kod. Predavač dobro balansiše između teorije i prakse, a pauza (~17 min) je bila jedina duža stanka.

---

## 4. Šabloni koje studenti trebaju znati
*(Korisno za pripremu vašeg predavanja)*

```cpp
// Provjera tipa karaktera
c >= 'a' && c <= 'z'   // malo slovo
c >= 'A' && c <= 'Z'   // veliko slovo
c >= '0' && c <= '9'   // cifra

// Konverzija veličine slova
(char)(c - 32)  // malo → veliko
(char)(c + 32)  // veliko → malo

// Unos stringa s razmacima
getline(cin, tekst);

// Prolazak kroz string
for (int i = 0; i < tekst.length(); i++) { ... }

// Izgradnja novog stringa
string novi = "";
novi += tekst[i];  // dodavanje karaktera

// Cezarova šifra (wraparound)
int novi = (slovo - 'a' + k) % 26;
(char)(novi + 'a');
```
