Maybe Monade
    C++ (Klasse und std::optional):
        Braucht explizite Klassen (Optional oder std::optional) und Handarbeit für Zustandsmanagement.
        Nutzt Methodenverkettung und funktionale Komposition; flexibel, aber komplex.
        Setzt auf Template-Metaprogrammierung; stark, aber weniger lesbar.

    Java:
        Nutzt Optional aus der Standardbibliothek; weniger elegant als Haskells Maybe.
        Fokussiert auf Methodenverkettung (flatMap); explizit, aber etwas umständlich.
        Kein eingebauter Mechanismus für knappe funktionale Komposition wie in Haskell, führt zu längeren Implementierungen.
    C#:
        Nullable-Typen + LINQ = easy & klar. SelectMany für Verkettung, wie Java's flatMap, aber C#-style.
        Einfach, ohne extra Klassen.

List Monade
    C++:
        Benutzt eine eigene MonadicList Klasse für monadisches Verhalten.
        mBind wird für Verkettungen genutzt, ist aber umständlicher als Java's flatMap.
        Explizite Iteration und manuelle Ergebnisakkumulation, aufwendiger als Java's Stream-Ansatz.

    Java (Streams):
        Nutzt die Stream API für monadische Operationen, was lesbarer und prägnanter ist.
        flatMap wird für die monadische Verkettung verwendet, was einen deklarativen Stil fördert.
        Passt besser zu funktionalen Programmierparadigmen und ist weniger umständlich als die C++ Variante.

    Java (Ohne Streams):
        Ähnlich wie C++ mit einer eigenen MonadicList Klasse, aber etwas knapper dank Java's Syntax.
        mBind wird für Verkettungen verwendet, ähnlich wie in C++, aber weniger wortreich.
        Weniger knapp als die Stream-Version, zeigt aber klar monadische Prinzipien in einem nicht-funktionalen Sprachkontext.

    C#:
        SelectMany für List-Monaden. Klar, kompakt, ähnlich wie Haskell.
        Einfacher als C++ oder Java ohne Streams. Passt gut in C#.

    Die C++ und Java Implementierungen (ohne Streams) benötigen eigene Klassen, wobei Java etwas prägnanter ist. Die Java Stream-Implementierung ist simpler und näher zur funktionalen Programmierung die C# implementierung verläuft ähnlich einfach.