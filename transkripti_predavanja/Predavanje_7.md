# Predavanje 7 — Meeting Recording

**Datum:** 28. mart 2026, 15:05  
**Trajanje:** 1h 42m 44s  
**Transkripciju pokrenula:** Edukacijska grupa Ada

---

## Transkript

---

**Edukacijska grupa Ada** `0:04`

Prošli put smo radili petlje — for i while — a ovaj put radimo nizove, koji su dosta usko vezani sa petljama. Jedno bez drugog često nema smisla koristiti.

Ideja iza nizova jeste sljedeća: ako vi pišete varijable, svaka varijabla mora imati neko ime. Zamislite da pravite mobilnu aplikaciju ili igricu i imate nekoliko neprijatelja na ekranu — svakom biste morali davati posebnu varijablu. Ako je taj broj neprijatelja možda 2 ili 3, to je ok — nazovete ih `neprijatelj1`, `neprijatelj2`, `neprijatelj3`. Ali zamislite da ne znate koliko imate neprijatelja ili da ih može biti stotinu — tada postaje jako nezgodno.

Taj problem upravo rješavaju **nizovi**.

Nizovi su kolekcija varijabli koje su sve istog tipa i koje su indeksirane. To znači da pored imena samog niza potrebno je specificirati i poziciju konkretne varijable unutar niza.

Kada deklarišemo niz, nakon imena niza pišemo uglaste zagrade i unutar njih koliko elemenata želimo:

```cpp
int mojNiz[5];
```

Ovo je u suštini isto kao da si napisao 5 zasebnih varijabli: `x1`, `x2`, `x3`, `x4`, `x5`.

---

**Edukacijska grupa Ada** `(nastavak)`

Svaki element niza se ponaša kao posebna varijabla. Pristupamo elementu u nizu tako što napišemo ime niza i zatim indeks unutar uglastih zagrada:

```cpp
mojNiz[0] = 30;
mojNiz[1] = 8;
mojNiz[2] = 10;
```

**Važno:** Ako imamo niz veličine 5, indeksi se kreću od `0` do `4` — ne od 1 do 5. Ovo je slučaj u 90% programskih jezika, uključujući C++.

Možemo ispisati element:

```cpp
cout << mojNiz[0]; // ispisuje 30
```

---

**kalajdzija.hamza** `6:06`

Možete li malo povećati ekran? Ne vidim dobro.

---

**Edukacijska grupa Ada** `6:11`

Da, naravno.

---

**Edukacijska grupa Ada** `(nastavak)`

Prava korist od nizova nije u tome što ne moramo pisati više varijabli — nego u tome što kada pristupamo elementima niza, unutar uglastih zagrada ne moramo pisati konkretne brojeve, nego možemo koristiti **varijable**:

```cpp
int index = 2;
cout << mojNiz[index]; // ispisuje treći element
```

I samim time, možemo koristiti **for petlju**:

```cpp
for (int i = 0; i < 5; i++) {
    cout << mojNiz[i] << "\n";
}
```

Ovo je nemoguće sa zasebnim varijablama — ali sa nizovima je sasvim moguće.

---

**Edukacijska grupa Ada** `(nastavak — nedefinirano ponašanje)`

Šta se desi ako pristupamo elementima van granica niza? Na primjer, imamo niz veličine 2, ali pokušamo unijeti i ispisati 3 elementa?

Odgovor je tzv. **nedefinirano ponašanje**. U velikoj većini slučajeva ne želite to — program može ispisati nasumične vrijednosti, ili može doći do greške (crash). U nekim slučajevima ćete čak dobiti negativan broj ili potpuno besmislenu vrijednost.

Uvijek pazite:
- Indeks ne smije biti manji od `0`.
- Indeks ne smije biti veći od `veličina niza - 1`.

Ovo je jedan od najvećih sigurnosnih problema u softveru danas — mnogi napadi na računare dešavaju se upravo ovako, kroz pristup memoriji van granica niza.

---

**Edukacijska grupa Ada** `(nastavak — unos i ispis niza)`

Ako želimo unijeti kompletan niz od korisnika, koristimo for petlju:

```cpp
int n = 5;
int mojNiz[10]; // niz dovoljne veličine

for (int i = 0; i < n; i++) {
    cin >> mojNiz[i];
}
```

Ispis u normalnom redoslijedu:

```cpp
for (int i = 0; i < n; i++) {
    cout << mojNiz[i] << "\n";
}
```

Ispis u **obrnutom** redoslijedu:

```cpp
for (int i = n - 1; i >= 0; i--) {
    cout << mojNiz[i] << "\n";
}
```

Ova dva šablona su jako česta i korisna.

---

**Edukacijska grupa Ada** `(nastavak — kopiranje nizova)`

U nekim slučajevima ćete morati kopirati nizove. Ne postoji kratka sintaksa za ovo — morate ručno pisati petlju:

```cpp
for (int i = 0; i < n; i++) {
    mojNiz2[i] = mojNiz[i];
}
```

---

**Edukacijska grupa Ada** `(nastavak — ograničenja nizova)`

Postoji jedno bitno ograničenje: **veličina niza mora biti poznata unaprijed**, i to kao konstanta. Osim toga, niz koji deklarišete unutar funkcije koristi ograničen prostor u memoriji (tzv. stack memorija), koji je reda veličine 4–6 megabajta.

Ako stavite niz veličine milion elemenata unutar funkcije:

```cpp
int mojNiz[1000000]; // problematično unutar funkcije!
```

Program može crashati jer se prekorači stack prostor.

**Rješenje za takmičarsko programiranje:** Koristite **globalne varijable**. Niz deklarisan van svih funkcija koristi drugačiji prostor u memoriji i može biti puno veći.

```cpp
int mojNiz[1000000]; // ok kao globalna varijabla

int main() {
    // ...
}
```

Moja preporuka:
- Do 100.000 elemenata — koristite niz (lokalno ili globalno).
- Od 100.000 do ~100 miliona — koristite vektore.

---

**alankayosh** `30:42`

Da li ima potrebe koristiti ovako velike nizove?

---

**Edukacijska grupa Ada** `30:59`

Da — na državnim takmičenjima ima zadataka gdje su vam potrebni nizovi koji su preveliki da stanu na stacku. Odgovor je: najčešće ne, ali ponekad da.

---

**Edukacijska grupa Ada** `(nastavak — zadatak 1)`

Zadatak: Napravite program koji:
1. Unese broj `n`.
2. Unese `n` elemenata u niz.
3. Ispiše te elemente u **obrnutom** redoslijedu.

Na primjer, za unos `6` elemenata: `1 2 3 4 5 6`, ispis bude: `6 5 4 3 2 1`.

---

**Edukacijska grupa Ada** `(nastavak — greške u rješenjima)`

Vidio sam da neka rješenja koriste indekse od `1` do `n` umjesto od `0` do `n-1`. Ovo je česta greška — validni indeksi su od `0` do `n-1`. Ako unesete `n = 10` i pristupate elementu na indeksu `10`, to je van granica niza.

Ispravni šabloni:
- **Unos:** `for (int i = 0; i < n; i++)`
- **Obrnuti ispis:** `for (int i = n-1; i >= 0; i--)`

---

**Edukacijska grupa Ada** `(nastavak — vektori)`

Nizovi imaju ograničenja:
1. Veličina mora biti poznata unaprijed.
2. Ne možete promijeniti veličinu niza nakon deklaracije.

Zbog toga postoje **vektori** — koji su napravljeni upravo da ova ograničenja prevaziđemo.

Deklaracija vektora:

```cpp
#include <vector>

vector<int> mojVektor;
```

Vektor na početku ima 0 elemenata. Dodajemo elemente koristeći `push_back`:

```cpp
mojVektor.push_back(10);
mojVektor.push_back(20);
mojVektor.push_back(30);
```

Sada vektor ima 3 elementa: `{10, 20, 30}`.

Pristup elementima je isti kao kod niza:

```cpp
cout << mojVektor[0]; // ispisuje 10
mojVektor[0] = 50;    // mijenja vrijednost
```

**Važno:** Možete pristupiti samo elementima koji postoje, tj. koji su dodani putem `push_back`. Pristup elementu koji nije dodan je isto kao pristup van granica niza — nedefinirano ponašanje.

---

**Edukacijska grupa Ada** `(nastavak — korisne metode vektora)`

**Veličina vektora:**

```cpp
cout << mojVektor.size(); // ispisuje 3
```

**Provjera da li je vektor prazan:**

```cpp
if (mojVektor.empty()) {
    // vektor je prazan
}
// ili:
if (mojVektor.size() == 0) { ... }
```

**Brisanje posljednjeg elementa:**

```cpp
mojVektor.pop_back();
// sada vektor ima 2 elementa
```

**Brisanje svih elemenata:**

```cpp
mojVektor.clear();
// vektor je sada veličine 0
```

**Kopiranje vektora** — za razliku od nizova, ovo je jednostavno:

```cpp
vector<int> mojVektor2 = mojVektor;
// mojVektor2 sada ima iste elemente kao mojVektor
```

Ako `mojVektor2` već ima neke elemente, oni će biti **zamijenjeni** — ne dodati.

**Dodavanje svih elemenata jednog vektora u drugi:**

```cpp
for (int i = 0; i < mojVektor.size(); i++) {
    mojVektor2.push_back(mojVektor[i]);
}
```

---

**vukasinvuk100** `1:09:23`

Hoće li kopiranje vektora dodati vrijednosti u drugi vektor ili ih zamijeniti?

---

**Edukacijska grupa Ada** `1:09:31`

Samo će zamijeniti — odlično pitanje. Ako `mojVektor2` već ima elemente `{100, 200, 300}` i uradimo `mojVektor2 = mojVektor`, oni će biti zamijenjeni novim elementima. Nije bitno koliko elemenata ima `mojVektor2` — sve će biti zamijenjeno.

---

**Edukacijska grupa Ada** `(nastavak — zadatak 2)`

Novi zadatak: Napravite program koji:
1. Korisnik unosi brojeve sve dok ne unese `0`.
2. Nakon toga, ispisuje koliko od unesenih brojeva je **manje** od posljednjeg unesenog broja (koji nije 0), i koliko je **veće**.

Na primjer, unos: `1 3 4 7 5 2 3 0`  
Posljednji uneseni broj (prije 0) je `3`.  
Manji od 3: `1, 2` → 2 broja  
Veći od 3: `4, 7, 5` → 3 broja

**Napomena:** Morate koristiti vektor jer ne znate unaprijed koliko brojeva će korisnik unijeti.

---

**Edukacijska grupa Ada** `(nastavak — zadaća)`

Zadaća za sljedeći put:

Korisnik unosi:
- Broj `n` — koliko brojeva će biti uneseno.
- Broj `maks` — najveći mogući broj koji može biti unesen (svi brojevi su između `1` i `maks`).
- `n` brojeva.

Program treba ispisati koliko se puta **svaki broj od 1 do maks** pojavljuje u nizu.

Na primjer:
- `n = 6`, `maks = 10`, unos: `3 6 2 2 3 8`
- Ispis:
  ```
  1: 0
  2: 2
  3: 2
  4: 0
  5: 0
  6: 1
  7: 0
  8: 1
  9: 0
  10: 0
  ```

---

**kosta.car2204** `1:39:41`

Malo nisam razumio zadatak, možete li pojasniti?

---

**Edukacijska grupa Ada** `1:39:44`

Naravno. Želim da brojiš koliko se puta koji broj pojavljuje u nizu. `n` je broj unesenih vrijednosti, a `maks` je najveći broj koji može biti unesen — svi uneseni brojevi su između `1` i `maks`. Za svaki broj od `1` do `maks` ispiši koliko puta se pojavio u nizu.

---

**kalajdzija.hamza** `1:41:22`

A što ako neko unese broj veći od `maks`?

---

**Edukacijska grupa Ada** `1:41:28`

Možete pretpostaviti da neće biti uneseno ništa veće od `maks` ili manje od `1`. Možete staviti neki `if` koji ispisuje "neispravan unos" za svaki slučaj, ali dovoljno je da pretpostavite da će ulaz biti ispravan.

---

**Edukacijska grupa Ada** `1:41:53`

Ima li još pitanja? Sutra u 16:00 imamo predavanje o stringovima. Hvala puno, vidimo se!

---

**vukasinvuk100** `1:42:23`

Sutra u 4, zadavajte zadaće.

---

**Edukacijska grupa Ada** `1:42:30`

Najvjerovatnije ću biti ja. U redu, vidimo se!

---

**Više učesnika** `1:42:40`

Do viđenja!

---

*Transkript završen.*
