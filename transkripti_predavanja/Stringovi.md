# Stringovi — Meeting Recording

**Datum:** 29. mart 2026, 16:04  
**Trajanje:** 1h 58m 48s  
**Transkripciju pokrenula:** Edukacijska grupa Ada

---

## Transkript

---

**Edukacijska grupa Ada** `0:35`

Danas radimo stringove. Izvinite, malo sam prehlađen.

Što se stringova tiče, prvo ćemo se malo podsjetiti na `char`. Kao što se sjećate, `char` je tip podataka koji se stavlja unutar jednostrukih navodnika i predstavlja **jedan jedini karakter**. Može biti slovo, cifra, razmak — ali strogo jedan znak.

```cpp
char c = 'A';   // validno
char c = '7';   // validno
char c = ' ';   // validno
char c = "AB";  // NIJE validno — char prima samo 1 karakter
```

---

**Edukacijska grupa Ada** `(nastavak — ASCII tabela)`

Zanimljiva stvar je što se svaki `char` u memoriji čuva kao **broj**. Ako ispišemo karakter kao `int`, dobit ćemo taj broj:

```cpp
char c = 'A';
cout << (int)c; // ispisuje 65
```

Ovo je moguće zato što postoji **ASCII tabela** — ona mapira svaki karakter u broj. Npr.:
- `'A'` → 65
- `'B'` → 66
- `'a'` → 97
- `'0'` → 48

Sva mala slova su uzastopna, sva velika slova su uzastopna, i sve cifre od `'0'` do `'9'` su uzastopne. To nam omogućava korisne manipulacije.

Na primjer:

```cpp
char c = 'a';
c = c + 1;       // c je sada 'b'
cout << c;       // ispisuje b

char ch = 'A';
cout << (int)ch; // 65
cout << ch + 1;  // ispisuje 66 (kao broj, ne slovo)
cout << (char)(ch + 1); // ispisuje 'B'
```

**Napomena o unikodu:** Za karaktere poput `č`, `ć`, `š` itd. postoji **Unicode tabela** koja pokriva sve jezike i pisma. Međutim, Unicode zauzima puno više memorije. Za zadatke na takmičenjima, uglavnom koristimo ASCII.

---

**Edukacijska grupa Ada** `(nastavak — zadatak 1: ispis abecede)`

**Zadatak:** Napisati program koji ispisuje sva mala slova abecede, a zatim sva velika slova, koristeći petlje i ASCII vrijednosti — dakle, bez da ih ručno navodite.

Rješenje:

```cpp
// Mala slova
for (char slovo = 'a'; slovo <= 'z'; slovo++) {
    cout << slovo;
}
cout << " "; // razmak između

// Velika slova
for (char slovo = 'A'; slovo <= 'Z'; slovo++) {
    cout << slovo;
}
```

---

**Edukacijska grupa Ada** `(nastavak — zadatak 2: malo ↔ veliko slovo)`

**Zadatak:** Unijeti jedan karakter. Ako je malo slovo, ispisati ga kao veliko; ako je veliko slovo, ispisati ga kao malo.

Ključna stvar: mala slova imaju veće ASCII vrijednosti od velikih. Na primjer:
- `'A'` = 65, `'a'` = 97 → razlika je **32**

Dakle:
- Malo → Veliko: oduzmi 32 (ili oduzmi `('a' - 'A')`)
- Veliko → Malo: dodaj 32 (ili dodaj `('a' - 'A')`)

```cpp
char slovo;
cin >> slovo;

if (slovo >= 'a' && slovo <= 'z') {
    // malo slovo → ispiši veliko
    cout << (char)(slovo - ('a' - 'A'));
} else if (slovo >= 'A' && slovo <= 'Z') {
    // veliko slovo → ispiši malo
    cout << (char)(slovo + ('a' - 'A'));
}
```

---

**Edukacijska grupa Ada** `(nastavak — zadatak 3: klasifikacija karaktera)`

**Zadatak:** Unijeti jedan karakter i ispisati je li to:
- Slovo (`slovo`)
- Broj (`broj`)
- Specijalni znak (`specijalni znak`)

```cpp
char karakter;
cin >> karakter;

if ((karakter >= 'a' && karakter <= 'z') ||
    (karakter >= 'A' && karakter <= 'Z')) {
    cout << "slovo";
} else if (karakter >= '0' && karakter <= '9') {
    cout << "broj";
} else {
    cout << "specijalni znak";
}
```

---

**Edukacijska grupa Ada** `43:36`

Sad prelazimo na stringove.

**String** je tip podataka koji čuva **niz karaktera**. Deklarira se sa dvostrukim navodnicima:

```cpp
string rijec = "Nina";
```

Za razliku od `char` (jedan znak — jednostruki navodnici), string može sadržavati koliko god karaktera hoćemo.

Da bi string radio, potrebno je uključiti odgovarajuće zaglavlje:

```cpp
#include <string>
// ili u praksi često dolazi automatski s #include <iostream>
```

---

**Edukacijska grupa Ada** `(nastavak — operacije sa stringovima)`

**Dužina stringa:**

```cpp
string niz = "Programiranje";
cout << niz.length(); // ispisuje 13
```

Veoma slično kao `size()` kod vektora — možete koristiti i `.size()`.

**Pristup pojedinačnom karakteru:**

```cpp
cout << niz[5]; // ispisuje 6. karakter (indeks 5)
```

Karakter dobijen na ovaj način je tipa `char` i može se pretvoriti u `int`:

```cpp
char c = niz[5];
cout << (int)c; // ispisuje ASCII vrijednost tog karaktera
```

**Spajanje (konkatenacija) stringova:**

```cpp
string pozdrav = "Zdravo, ";
string ime = "Ahmet";
string poruka = pozdrav + ime; // "Zdravo, Ahmet"
cout << poruka;
```

**Prolazak kroz string for petljom:**

```cpp
for (int i = 0; i < niz.length(); i++) {
    cout << niz[i] << "\n";
}
```

Postoji i moderniji (range-based) način:

```cpp
for (auto slovo : niz) {
    cout << slovo << "\n";
}
```

Za sad ćemo koristiti klasičnu for petlju jer daje veću kontrolu.

---

**Edukacijska grupa Ada** `(nastavak — unos stringa)`

Standardni unos sa `cin` radi za jednu riječ:

```cpp
string tekst;
cin >> tekst; // prima samo do prvog razmaka
```

Ako želimo unijeti cijelu rečenicu (sa razmacima), koristimo `getline`:

```cpp
string tekst;
getline(cin, tekst); // prima cijelu liniju uključujući razmake
```

---

**Edukacijska grupa Ada** `1:16:20`

Nastavljamo sa zadacima.

---

**Edukacijska grupa Ada** `(nastavak — zadatak 4: string unazad)`

**Zadatak:** Učitati string od korisnika i ispisati ga u obrnutom redoslijedu.

Na primjer: ulaz `programiranje` → izlaz `ejarinargorп`

```cpp
string rijec;
cin >> rijec;

for (int i = rijec.length() - 1; i >= 0; i--) {
    cout << rijec[i];
}
```

---

**Edukacijska grupa Ada** `(nastavak — zadatak 5: palindrom)`

**Zadatak:** Napisati program koji provjerava da li je unesena rečenica palindrom, ali pri tome **ignorisati razmake**.

Na primjer:
- `"ursisrona"` — palindrom ✓
- `"race car"` — palindrom (bez razmaka: `racecar`) ✓
- `"anna"` — palindrom ✓
- `"laurel"` — nije palindrom ✗

**Pristup:**
1. Skinuti sve razmake iz teksta
2. Provjeriti da li je dobiveni string palindrom

```cpp
string tekst;
getline(cin, tekst);

// Korak 1: skloniti razmake
string tekstBezSpisa = "";
for (int i = 0; i < tekst.length(); i++) {
    if (tekst[i] != ' ') {
        tekstBezSpisa += tekst[i];
    }
}

// Korak 2: provjera palindroma
bool jePalindrom = true;
for (int i = 0; i < tekstBezSpisa.length(); i++) {
    if (tekstBezSpisa[i] != tekstBezSpisa[tekstBezSpisa.length() - 1 - i]) {
        jePalindrom = false;
        break;
    }
}

if (jePalindrom) {
    cout << "Palindrom";
} else {
    cout << "Nije palindrom";
}
```

---

**Edukacijska grupa Ada** `(nastavak — zadatak 6: Cezarova šifra)`

**Zadatak:** Unijeti string (rečenicu) i broj `k`. Svako slovo pomaknuti za `k` mjesta unaprijed u abecedi, uz **ciklično ponašanje** (npr. `z + 3 = c`). Ostale znakove (razmaci, interpunkcija) ne mijenjati.

Na primjer za `k = 3`:
- `h` → `k`
- `e` → `h`
- `z` → `c` (wraparound)

Radi za **mala i velika** slova odvojeno.

**Ključni koncepti:**

Koristimo modulo (`%`) za ciklično ponašanje:

```cpp
// Za vrijednosti 0–5, kad dodaš 1 na 5, dobiješ 0:
(broj + 1) % 6
```

**Formula za pomicanje slova:**

```cpp
// Koji je broj po redu abecedi (0-indexirano)?
int redniBroj = slovo - 'a';        // za mala slova
int redniBroj = slovo - 'A';        // za velika slova

// Pomakni za k, uz wraparound:
int noviRedniBroj = (redniBroj + k) % 26;

// Pretvori nazad u karakter:
char novoSlovo = (char)(noviRedniBroj + 'a');  // za mala
char novoSlovo = (char)(noviRedniBroj + 'A');  // za velika
```

**Kompletno rješenje:**

```cpp
string tekst;
int k;
getline(cin, tekst);
cin >> k;

for (int i = 0; i < tekst.length(); i++) {
    char c = tekst[i];

    if (c >= 'a' && c <= 'z') {
        // malo slovo
        int redniBroj = c - 'a';
        int noviRedniBroj = (redniBroj + k) % 26;
        cout << (char)(noviRedniBroj + 'a');
    } else if (c >= 'A' && c <= 'Z') {
        // veliko slovo
        int redniBroj = c - 'A';
        int noviRedniBroj = (redniBroj + k) % 26;
        cout << (char)(noviRedniBroj + 'A');
    } else {
        // razmak ili specijalni znak — ne mijenjati
        cout << c;
    }
}
```

---

**Edukacijska grupa Ada** `1:58:32`

Nema pitanja? U redu, vidimo se sljedeći put!

---

**Više učesnika** `1:58:41`

Do viđenja!

---

*Transkript završen.*
