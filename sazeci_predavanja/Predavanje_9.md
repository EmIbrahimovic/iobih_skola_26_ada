# Predavanje 9 — Meeting Recording

**Datum:** 18. april 2026, 14:05  
**Trajanje:** 1h 38m 29s  
**Transkripciju pokrenula:** Edukacijska grupa Ada

---

## Transkript

---

**Edukacijska grupa Ada** `0:05`

Zapravo sam počeo ranije snimati, ali nismo ništa još počeli raditi konkretno. Spasao sam prisustvo ako neko dobije imejl da nije prisutan. Do sada ste radili, koliko ja znam — jer nisam nisam držao teta predavanjem — dosta radili sa sport petlja for.

---

**vukasinvuk100** `0:50`

Izvinite, da ostavi prozivali za prisutnost.

---

**Edukacijska grupa Ada** `0:54`

A nisam prozivao, sam gledao ko je došo tu. Tako da mislim, ako slučajno tebe nisam dodao, da će šimel tom zemljom, ali provjerio sam. Nadamo se da sam, a za neke for petlje i manje od nekog bratstva i plus plus i onda vam ovde nešto ide wild petlja.

---

**vukasinvuk100** `0:59`

Aha, dobro. Dobro je dobro.

---

**Edukacijska grupa Ada** `1:18`

Takođe, uslov je da se izvodi do-while petlja. Uspostavljanje kraja igre. Da li nekome nije jasno? Ovo nije bio vođa dio današnjeg predavanja, ali na kom je jasno — šta je razmeđa while i do-while petlje. Ako znate, sigurno znate, ne morate, ali nekome treba dodatno objašnjenje.

Vidim podignuta jednu ruku.

---

**vanja.arsenovski** `1:49`

Molim, objasni, znači to dugo.

---

**Edukacijska grupa Ada** `1:52`

Do-while petlja tu se da — to ste imali na predavanjima — razlika između while i do-while petlje jeste sljedeća.

While petlja funkcioniše na način da imate neki uslov, recimo: dok je `x < 1000`:

```cpp
while (x < 1000) {
    // ...
}
```

Do-while petlja će uvijek izvršiti bar jednu iteraciju, bez da provjeri da li je uslov ispunjen na samom početku. Jedina razlika između while i do-while petlje jeste: u while petlji, prvi put kada dođete — znači na samom početku — provjeri se da li je uslov tačan, i ako jeste nastavlja, ako nije, preskočiće. Znači, ako krenemo da je `x = 100` i pokrenemo program i specificiramo `x < 100`, prazno je — jer pri prvoj provjeri, prvooj iteraciji, kad je `x = 100`, nije tačno.

S druge strane, do-while petlja će uvijek u barem jednoj iteraciji izvršiti kod. Petlja se uvijek izvršiti, čak i ako uslov nije ispunjen — znači od samog starta `x` daje manje od 0. Ovo 100 definitivan je manje od gornje granice, ali će uvijek izdržati barem jednu iteraciju.

Do-while petlje nisu toliko često korisne — for petlje su mnogo češće korisne. Kada budete pisali, mnogo češće koristit ćete for petlje nego while/do-while petlje.

---

**marijamitrovic2013** `7:04`

Izvinite, je li to znači onda kada koristimo do-while, da se svakako jednom izvrši, i onda se tek provjerava?

---

**Edukacijska grupa Ada** `7:12`

Tako je. Može biti uslov koji je na početku odmah netačan — pa će se i dalje definitano jedanput izvršiti. Kad bi stavili to istu petlju kao while petlju, ne bi se izvršila ni jedanput jer uslov nije ispunjen.

Dakle, to je razlika. Sad možemo, recimo — isto kao što može praviti for petlju — hajde da napravimo:

```cpp
for (int i = 0; i < 10; i++) {
    // ...
}
```

U bloku koda ove forme, možemo staviti još jednu for petlju. Za bilo koji tip petlje može tu while, do-while, ili for, ali najčešće se koriste for petlje.

---

**Edukacijska grupa Ada** `(nastavak)`

Međutim, ono što je jako bitno zapamtiti — ako imate ugniježđene for petlje, ovako — morate koristiti dvije varijable kao brojače. Znači umjesto `i` i `i`, po konvenciji najčešće ćete vidjeti `int i` i `int j`.

```cpp
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        // ...
    }
}
```

Jaka česta greška koju prave u početku — ja sam mnogo puta napravio — jeste da se zaboravi koristiti drugačiju varijablu. Ovo je potpuno validno kompajleru — nikakvu grešku neće dati. Morate vi ručno paziti da koristite drugačije varijable.

Za svaку iteraciju vanjske for petlje, prođemo kroz sve moguće vrijednosti unutarnje for petlje. Na čijoj će biti od 0 do 9.

Sada možemo napisati nešto, recimo:

```cpp
cout << i << " * " << j << " = " << i * j << endl;
```

Pokrenemo i vidimo — ispis množenja svih parova brojeva.

---

**Edukacijska grupa Ada** `(nastavak)`

Jaka česta greška: ako slučajno koristite iste brojače u ugniježđenim for petljama — recimo umjesto `j`, opet `i` — dobit ćete beskonačnu petlju. Zašto? Zato što vanjska for petlja svaki puta povećava `i`, ali uslov za završetak unutarnje petlje je `i < 10`, i `i` se sve više povećava i nikad ne završava normalno.

Ovo je mala greška — jako, vrllo jednostavno napraviti — ali morate paziti.

---

**Edukacijska grupa Ada** `~21:00`

Sada vam dajem zadatak: pokušajte napisati kod koji ispisuje desni jednakokraki pravougaoni trougao od zvjezdica.

Na primjer, za `n = 4`:
```
*
**
***
****
```

To vam je sada zadatak — napišite to.

---

**kalajdzija.hamza** `21:04`

Zašto se to čita samo?

---

**Edukacijska grupa Ada** `21:06`

Mogao bi. To da lakše.

---

**Edukacijska grupa Ada** `~26:00`

Jedna stvar koju sam primijetio — nije ni opšte tačna, ali možda ćete oboje znati. Poslije, kad pišete zvjezdicu, napišete ovako: `cout << "*"` — što je sasvim ispravno. Ali druga opcija, alternativa, je da se koristi jednostruki navodnik: `cout << '*'`.

Razlog za to je što dvostruki navodnici u C++ prepoznaju se kao string — niz karaktera — dok jednostruki navodnik prepoznaje samo jedan karakter (`char`). Tehnički, malo je brže s jednostrukim navonicima, jer kompajler zna da se radi o jednom karakteru i ne mora pozivati kod koji ispisuje string sastavljene od niza znakova.

Ako stavljate više od jednog karaktera, obavezno koristite dvostruke navodnike.

---

**Edukacijska grupa Ada** `~32:00`

Hajde sada da pređemo na nešto malo teži zadatak — praviti tablicu množenja.

Ispisati rezultate množenja svih parova brojeva od 1 do 10. Dakle prava tablica množenja. Nešto ovako:

```
1  2  3  4  5  6  7  8  9  10
2  4  6  8  10 12 14 16 18 20
...
```

Zadatak je — napišite kod koji ispisuje tablicu množenja.

---

**kalajdzija.hamza** `35:49`

Samo rezultate, tačno?

---

**Edukacijska grupa Ada** `35:52`

Da, da. Ovo je ok. Možda malo jednostavnijim ispisom. Ne mora svaki zadatak biti težak.

---

**Edukacijska grupa Ada** `~50:00`

Sada ćemo koristiti i vektore koje smo radili na prošlim predavanjima — predavanju 7.

Koristit ćemo vektore. Napravimo neki vektor s brojevima.

**1. korak:** Unesite broj `n`.  
**2. korak:** Unesite `n` brojeva i sačuvajte ih u vektor.

Sada objasnim koncept **podnizan (subarray)**. Ako imamo neki niz, npr. vektora:

```
1 2 3 4 5 6 7
```

Podniz je bilo koja uzastopna kombinacija nekog početnog i krajnjeg indeksa unutar tog vektora. Npr. `{2, 3, 4}` je podniz, `{5, 6, 7}` je podniz, `{2}` je podniz. Ono što **nije** podniz su brojevi koji nisu uzastopni.

**3. korak:** Ispisati podniz sa **najvećim zbirom**.

To znači da morate pronaći koji uzastopni niz elemenata unutar vektora ima najveći mogući zbir.

Na primjer, kada svi elementi su pozitivni — trivijalno je, jer je cijeli niz ujedno i podniz s najvećim zbirom. Ali, šta kad imamo:

```
1 2 3 -6 5 6
```

Tada moramo promišljati koje elemente uključiti. Recimo, podniz `{5, 6}` daje zbir 11, ali `{1, 2, 3, 5, 6}` nije podniz jer nisu uzastopni. Morali bismo uzeti `-6` ako uzmemo sve, što smanjuje zbir.

**Hint:** Možete proći kroz sve moguće kombinacije početnog i krajnjeg indeksa:

```cpp
for (int i = 0; i < n; i++) {        // početak podniza
    for (int j = i; j < n; j++) {    // kraj podniza
        // saberi sve elemente od i do j
        // prati maksimalni zbir
    }
}
```

Postoji i optimizacija — umjesto 3 for petlje (treća za sabiranje), možete držati tekući zbir i ažurirati ga svaki put kad proširite kraj podniza.

Postoji čak i rješenje s jednom for petljom.

---

**kosta.car2204** `1:13:07`

Je li prosti broj taj kod kojeg su svi djelitelji samo sam broj i broj 1?

---

**Edukacijska grupa Ada** `1:13:12`

Jeste, tako je. Prosti broj je broj koji je djeljiv samo sa samim sobom i brojem 1. Broj 1 se ne računa kao prosti broj, inače — ali 2, 3, 5, 7, 11, 13, 17, 19 i tako dalje — to su prosti brojevi.

**Zadatak:** Napisati kod koji ispisuje sve proste brojeve od `1` do `n`, gdje `n` korisnik unosi.

**Optimizacija:** Razmislite o tome — da li morate provjeravati djeljive sa svim brojevima manjim od `n`?

- Možete preskočiti parne brojeve (osim 2).
- Ne morate provjeravati djeljitelje veće od `√n`, jer ako je broj djeljiv s nekim faktorom većim od `√n`, drugi faktor mora biti manji od `√n`.

---

**Faris Fadžan** `1:14:53`

Slučajno sam podigao ruku.

---

**Edukacijska grupa Ada** `1:14:54`

Ok, znači pokušajte zadatak. Za zabavno, vratit ćemo se i onda ću vam dati još jedan zadatak.

---

**Edukacijska grupa Ada** `~1:30:00`

Posljednji zadatak za danas: Unesite broj `n` i `n` brojeva. Ispisati niz bez duplikata.

Znači ispisati sve brojeve, ali svaki jedanput — preskočiti sve ponavljajuće (duplikate).

---

**Edukacijska grupa Ada** `~1:36:00`

Možete i napraviti lijep dijagonalni trougao od zvjezdica, npr.:

```
*
**
***
****
*****
```

Poenta je da nacrtate ovaj oblik. Gornje linije sastoje se od više zvjezdica, dijagonala se sastoji od zvjezdica, dok su ostala polja prazna. Što je `n` veći, izgleda ljepše.

Ima li kakvih pitanja? Znamo da smo imali kraće predavanje, ali za sljedeće ćemo imati više.

---

**kalajdzija.hamza** `1:37:47`

Tu zajedno s posla i to kao noviji dio ovde u nastavi.

---

**Edukacijska grupa Ada** `1:37:53`

A naravno, može, može.

---

**Edukacijska grupa Ada** `1:38:00`

Ne zaboravite — sutra također ima predavanje. Sutra vam drži Eva. Sve o vektorima, matricama i tako to. Sretno, vidimo se za neki mjeec dana opet.

---

**kalajdzija.hamza** `1:38:22`

Do viđenja.

---

**Edukacijska grupa Ada** `1:38:24`

Ćenja.

---

*Transkript završen.*
