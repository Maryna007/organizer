# Organizer
## Specyfikacja funkcjonalna

### Główne elementy

Aplikacja, zwana dalej organizerem, zawiera podstawowe elementy każdego kalendarza takie jak podział na: 
-godziny, 
-dni, 
-tygodnie, 
-miesiące, 
-lata.
Użytkownik może dodać nowy wpis w wybranym przez siebie terminie.
Głównym celem istnienia organizera jest skuteczne planowanie własnego czasu w
zależności od wydarzeń, w których uczestniczy użytkownik.

### Dodatkowe funkcjonalności

Organizer wyposażony jest w kilka udogodnień, dodających nowe, funkcjonalne elementy,
usprawniające pracę z aplikacją. Organizer zawiera następujące moduły:
- Nadchodzące wydarzenia:
	- Element aplikacji umożliwiający użytkownikowi wyświetlenie wydarzeń mających miejsce, we wskazanym przez użytkownika dniu, miesiącu.  
	- Użytkownik ma możliwość przejrzenia zbliżających się wydarzeń w bieżącym miesiącu.
- Wyświetlenie wydarzenia:
	- Użytkownik może zobaczyć dopiero stworzone wydarzenie i również przechowywane w pamięci, potem usunąć lub zachować w pliku.
- Wyświetlenie kalendarza:
	- Możliwość wyświetlenia kalendarza zarówno na wyznaczony przez użytkownika miesiąc lub rok.

### Struktura programu :

#### Trzy podstawowe klasy:

1.Calendar - jest odpowiedzialna za wyświetlenie kalendarza i opcji które może wybrać użytkownik. Także istnieją metody do tworzenia, przechowywania, wyświetlania, wyszukiwania i usuwania wydarzeń. Pola klasy zawierają konterner vector, przechowujący wydarzenia, które jeszcze nie zostały zapisane do pliku. 
	
2.Event - przechowuje pola z datą i informacjami o wydarzeniu oraz zawiera metodę łączącą pola w rekordy kalendarza.

3.Date - zawiera metody do pobierania daty od użytkownika, sprawdzania jej poprawności, obliczeń potrzebnych do poprawnego wyświetlenia kalendarza. Obiekt klasy |Date  wchodzi w skład 2 wyżej wymienionych klasach.





