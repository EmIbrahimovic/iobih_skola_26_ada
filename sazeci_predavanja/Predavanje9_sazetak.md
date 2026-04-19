# Predavanje 9 — Sažetak Predavanja
**Datum:** 18. april 2026 | **Trajanje:** 1h 38m 29s  
**Predavač:** Edukacijska grupa Ada  
**Publika:** Talentovani učenici osnovne škole, početnici u programiranju

---

## 1. Teme i vremenski raspored

### Ponavljanje: `while` vs. `do-while` petlja — cca. 0:00–10:00 (10 min)
- Kratki uvod — predavač napominje da ovo nije centralna tema dana, ali jedan student je tražio pojašnjenje
- **While petlja:** uslov se provjerava na početku svake iteracije; ako je uslov odmah netačan, petlja se ne izvršava ni jednom
- **Do-while petlja:** tijelo se izvršava najmanje jedanput, uslov se provjerava tek na kraju
- Naglašeno: do-while petlje se rijetko koriste u praksi — for petlje su daleko najčešće
- Ilustrirano primjerom gdje `x = 100` i uslov je `x < 100`

### Ugniježđene for petlje — cca. 10:00–21:00 (11 min)
- Koncept: za svaku iteraciju vanjske petlje, unutarnja petlja prolazi kroz sve svoje vrijednosti
- Konvencija: vanjska petlja koristi `i`, unutarnja `j` (ili `k` za treću)
- **Česta greška #1:** korištenje istog brojača (`i`) u obje petlje — kompajler ne prijavljuje grešku, ali logika je pogrešna
- **Česta greška #2:** korištenje istog brojača uzrokuje beskonačnu petlju (vanjska petlja povećava `i`, unutarnja nikad ne završava)
- Demonstracija: ispis tablice množenja oblika `i * j = rezultat`

```cpp
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        cout << i << " * " << j << " = " << i * j << endl;
    }
}
```

### Digresija: `char` vs. `string` literal — cca. 26:00–30:00 (4 min)
- Predavač primijetio da studenti koriste `"*"` (string) za ispis jednog znaka
- Pojašnjenje: `'*'` (char) je tehnički brže jer kompajler zna da se radi o jednom karakteru
- Pravilo: jedan znak → jednostruki navodnici; više znakova → dvostruki navodnici

### Podnizovi (subarrays) — cca. 50:00–1:14:00 (24 min)
- Definicija: **podniz** je bilo koji uzastopni skup elemenata unutar vektora (određen početnim i krajnjim indeksom)
- Razlika: `{2, 3, 4}` je podniz; `{1, 3, 6}` (neuzastopni) **nije** podniz
- Zadatak: pronaći podniz s **najvećim zbirom**
- Razmatrani slučajevi: svi pozitivni elementi (trivijalan), negativni elementi (netrivijalan)
- Pristupi objašnjeni:
  - **O(n³):** tri ugniježđene petlje (jedna za početak, jedna za kraj, jedna za sabiranje)
  - **O(n²):** dvije petlje + tekući zbir koji se ažurira proširivanjem kraja podniza
  - **O(n):** postoji rješenje s jednom petljom (napomenuto, nije demonstrirano)

### Prosti brojevi — cca. 1:13:00–1:30:00 (17 min)
- Definicija: broj djeljiv samo sa samim sobom i jedinicom (`1` se ne računa)
- Primjeri: 2, 3, 5, 7, 11, 13, 17, 19...
- Zadatak: ispisati sve proste brojeve od `1` do `n`
- Optimizacije objašnjene:
  - Preskočiti parne brojeve (osim 2)
  - Provjeravati djeljitelje samo do `√n` (matematičko obrazloženje dato)

### Niz bez duplikata — cca. 1:30:00–1:38:00 (8 min)
- Zadatak: unijeti `n` brojeva i ispisati ih bez ponavljanja
- Dat kao posljednji zadatak dana, bez detaljnog objašnjenja pristupa

---

## 2. Primjeri i zadaci

### Primjer — Ilustracija while vs. do-while (cca. 0:00–10:00)
Predavač je demonstrirao razliku verbalnim primjerom i pseudokodom:
```cpp
// while — ne izvršava se ako je x = 100 i uslov x < 100
while (x < 100) { ... }

// do-while — izvršava se jednom čak i ako x = 100
do { ... } while (x < 100);
```

---

### Primjer — Ugniježđene petlje i česte greške (cca. 10:00–21:00)
Demonstracija ispravne upotrebe s različitim brojačima, i dvije greške uživo:
```cpp
// ISPRAVNO
for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
        cout << i * j;

// GREŠKA — isti brojač, beskonačna petlja
for (int i = 0; i < 10; i++)
    for (int i = 0; i < 10; i++)  // vanjski i se mijenja, unutarnji uslov nikad ne završi
        cout << i * i;
```

---

### Zadatak 1 — Trougao od zvjezdica (cca. 21:00–32:00)
**Cilj:** Ispisati desni jednakokraki pravougaoni trougao za unijeto `n`.

```
*
**
***
****
```

Riješen ugniježđenim for petljama. Studenti su ga brzo riješili.  
Uz to, predavač je napomenuo razliku između `"*"` i `'*'`.

---

### Zadatak 2 — Tablica množenja (cca. 32:00–50:00)
**Cilj:** Ispisati tablicu množenja svih parova od 1 do 10.

```
1  2  3  ...  10
2  4  6  ...  20
...
```

Riješen ugniježđenim for petljama. Studenti su pitali da li trebaju lijepo poravnati ispis — predavač rekao da nije obavezno.

---

### Zadatak 3 — Podniz s najvećim zbirom (cca. 50:00–1:13:00)
**Cilj:** Unijeti vektor od `n` elemenata (mogu biti negativni) i pronaći podniz s najvećim mogućim zbirom.

**Hint dat studentima:**
```cpp
for (int i = 0; i < n; i++) {         // početak podniza
    for (int j = i; j < n; j++) {     // kraj podniza
        // saberi elemente od i do j
        // ažuriraj maksimalni zbir
    }
}
```

Napomenuto da postoji optimizacija s tekućim zbirom (O(n²)) i čak rješenje s jednom petljom (O(n)). Studenti su radili samostalno — predavač pregledao rješenja i komentarisao.

---

### Zadatak 4 — Prosti brojevi od 1 do n (cca. 1:13:00–1:30:00)
**Cilj:** Ispisati sve proste brojeve od 1 do unesenog `n`.

Studenti pozvani da razmisle o optimizaciji:
- Preskočiti parne (osim 2)
- Provjeravati djelitelje samo do `√n`

---

### Zadatak 5 — Niz bez duplikata (cca. 1:30:00–1:38:00)
**Cilj:** Unijeti `n` brojeva i ispisati ih bez ponavljanja (svaki broj jedanput).

Dat kao završni zadatak bez detaljnog walkthrough-a — studenti su radili samostalno.

---

### Bonus — Dijagonalni trougao od zvjezdica (cca. 1:36:00)
**Cilj:** Ispisati trougao gdje su ispunjene samo gornja stranica i dijagonala, ostatak su prazna mjesta.

```
*****
 ****
  ***
   **
    *
```

Dat kao bonus za brže studente. Napomenuto da efekt izgleda ljepše za veće `n`.

---

## 3. Angažovanje studenata i interakcija

### Stil predavanja
Predavač je koristio **live coding** kombinovan s postavljanjem zadataka studentima za samostalan rad. Studenti su slali rješenja putem chata koja je predavač pregledao. Ton je bio neformalan i opušten — predavač se šalio i pohvaljivao studente. Primjetno je da predavač nije autor prethodnih predavanja (napominje da "nije držao ta predavanja"), što znači da se i sam uhodavao s grupom.

### Odziv studenata
Studenti su bili **aktivno angažovani**, postavljali su pitanja i brzo rješavali zadatke. Faris je slučajno podigao ruku i to je stvorilo mali šaljivi trenutak — što govori o opuštenoj atmosferi na času.

Aktivniji učesnici:
- **Vanja Arsenovski** — tražio pojašnjenje do-while petlje na početku
- **Marija Mitrović** — postavila precizno pitanje o do-while ("znači da se svakako jednom izvrši?")
- **Hamza Kalajdžija** — pitao o zadatku s trouglom i tablici množenja
- **Kosta Car** — postavio pitanje o definiciji prostih brojeva
- **Faris Fadžan** — slučajno podigao ruku (šaljivi trenutak)

### Procjena vremena interakcije

| Vrsta interakcije | Trajanje (approx.) |
|---|---|
| Provjera prisutnosti / organizacione napomene | ~3 min |
| Pitanja i odgovori tokom objašnjavanja | ~10 min |
| Pregled rješenja studenata i komentari | ~18 min |
| Završna pitanja i dogovor | ~4 min |
| **Ukupno** | **~35 min (~36% časa)** |

### Opšta napomena
Predavač je napomenuo da je ovo bilo **kraće predavanje** od uobičajenog i da će sljedeće biti opsežnije. Čas je završio nešto ranije. Sutradan je zakazano predavanje koje drži drugi predavač (Eva) — tema: vektori i matrice.

---

## 4. Šabloni koje studenti trebaju znati
*(Korisno za pripremu vašeg predavanja)*

```cpp
// Do-while petlja
do {
    // tijelo se izvršava bar jednom
} while (uslov);

// Ugniježđene for petlje — ispravno
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // koristite i i j — nikad isti brojač!
    }
}

// Trougao od zvjezdica
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) cout << '*';
    cout << '\n';
}

// Podniz s najvećim zbirom (O(n²))
int maxZbir = INT_MIN;
for (int i = 0; i < n; i++) {
    int tekuciZbir = 0;
    for (int j = i; j < n; j++) {
        tekuciZbir += v[j];
        maxZbir = max(maxZbir, tekuciZbir);
    }
}

// Provjera prostog broja
bool jeProst = (n > 1);
for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) { jeProst = false; break; }
}

// Char literal vs. string literal
cout << '*';   // char  — brže, jedan karakter
cout << "*";   // string — sporije, niz karaktera
```
