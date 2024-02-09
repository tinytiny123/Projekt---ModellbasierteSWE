Maybe Monade
    C++ (Klasse und std::optional):
        Braucht explizite Klassen (Optional oder std::optional) und Handarbeit für Zustandsmanagement.
        Nutzt Methodenverkettung und funktionale Komposition; flexibel, aber komplex.
        Setzt auf Template-Metaprogrammierung; stark, aber weniger lesbar.
		Im gegenzug zu haskell, wird hier ein Feld mit dem Wert als auch eine boolean flag für die Existenz des Wertes benötigt, wohingegen in Haskell der Wert in Just oder Maybe gewrapped wird.
		C++ profitiert von leichter erweiterbarkeit und mächtigen möglichkeiten zur überladung. So kann zum Beispiel funktionale verkettung leicht ermöglicht werden, aber auch das verketten mittels bind syntaktisch schöner gemacht werden durch das übreladen des >>= operators.
    Java:
        Nutzt Optional aus der Standardbibliothek; weniger elegant als Haskells Maybe.
        Fokussiert auf Methodenverkettung (flatMap); explizit, aber etwas umständlich.
        Kein eingebauter Mechanismus für knappe funktionale Komposition wie in Haskell, führt zu längeren Implementierungen.
		Java's Optional<T> hilft, Null-Probleme zu umgehen. Es ist ähnlich wie in der C++ Implementierung, ein Wrapper, der entweder einen Wert oder keinen Wert enthält. 
		Im Gegensatz zu Haskells maybe sind in der Verwendung von Javas Optional oftmals auch runtime checks via "isPresent()" oder "orElseThrow()" von nöten um sicheren Zugriff oder Manipulation der Variable sicherzustellen.
		Haskells Maybe ist anders. Es ist direkt im Typsystem verankert. Das macht den Umgang mit optionalen Werten einfacher und sicherer. Man nutzt Typinferenz und Musterabgleich, um Werte zu verarbeiten.
		Es gibt weniger Overhead als bei Java's Optional.
		Java fördert mit Optional einen funktionalen Stil, aber umständlicher. Haskell macht es von vornherein einfacher, dank seiner funktionalen Natur.
    C#:
        Nullable-Typen + LINQ = easy & klar. SelectMany für Verkettung, wie Java's flatMap, aber C#-style.
        Einfach, ohne extra Klassen.
		Die implementierung mittels "T?" erzeugt intern ein Objekt der Klasse Nullable<T>, welches ähnlich wie in c++ und java Wert und bool flag hält.
		Monadische verkettung erfolgt via LINQ(Language Integrated Query) SelectMany, welches ähnlich wie in Haskell ein Monadisches bind erzeugt, und die folgende expression nur ausführt falls die vorangegangene Expression nicht zu null evaluated.
		Bei funktionsdefinition kann entweder null oder ein Wert des Typen T returned werden. Entsprechend wird das Objekt des Typen Nullable erzeugt, das value falls vorhanden gesetzt und die bool flag dementsprechend angepasst.  
		Im Beispiel der DivSafe methode, wird also entweder ein Nullable<int>, dessen HasValue eigenschaft false ist im fall "if (m == 0) return null;" zurückgegeben oder aber ein Nullable<int> dessen HasValue true ist, und entsprechend auch das ergebnis der division hält.
		Im vergleich zu haskell erzeugt das führen des Nullable Objekts zu mehr overhead als die native maybe Monade und erfordert mehr runtime checks wie das prüfen des HasValue properties oder dem Abfangen der exception beim call von .Value, wenn ein solches nicht vorhanden ist.
		Syntaktisch deutlich schöner als Java oder C++, intern allerdings ähnlich.
List Monade
    C++:
        Benutzt eine eigene MonadicList Klasse für monadisches Verhalten.
		Diese Methode erfordert, dass man manuell durch jedes Element der Liste geht und die gewünschte Funktion darauf anwendet.
		Im Vergleich zu anderen Sprachen ist dieser Prozess weniger automatisiert und verlangt vom Entwickler mehr Eingriffe.
        mBind wird für Verkettungen genutzt, ist aber umständlicher als Java's flatMap.
        Explizite Iteration und manuelle Ergebnisakkumulation, aufwendiger als Java's Stream-Ansatz.
		Im gegensatz zu Haskell sind hier weder Syntaktischer Zucker noch effizienz optimierungen wie lazy evaluation zu finden.
    Java (Streams):
        Nutzt die Stream API für monadische Operationen, was lesbarer und prägnanter ist.
		Hierbei wird via stream() aus einer collection ein stream gemacht, welcher dann mit lamdas parallel oder sequenziell in funktionalem Stil verarbeitet werden kann.
        "flatMap" wird hierbei für die monadische Verkettung verwendet, ähnlich zu bind. Die flatMap operation wendet eine methode auf jedem Element des input Streams an und flattened dannach die Resultierenden streams zu einem einzelnen.
		Mittels collect wird dann wieder eine collection aus dem resultierenden Stream gemacht. 
		Im gegenzug zu haskells implementierung, findet in Java spätestens beim call zu collect die evaluierung der Werte statt. 
		Haskell kann hier hingegen durch die lazy evaluation die auswärtung bis zu dem Zeitpunkt an dem die Werte tatsächlich benötigt werden verschieben.
        Passt besser zu funktionalen Programmierparadigmen und ist weniger umständlich als die C++ Variante.
    Java (Ohne Streams):
        Ähnlich wie C++ mit einer eigenen MonadicList Klasse, aber etwas knapper dank Java's Syntax.
		Die Syntax und die Verwendung des Function-Interfaces erleichtern zwar das Verständnis und die Handhabung etwas, erreichen aber nicht die Simplizität und Direktheit von Java mit Streams oder die von Haskell. 
        mBind wird für Verkettungen verwendet, ähnlich wie in C++, aber weniger wortreich.
		In Java werden, wie auch in C++, Operationen sofort ausgeführt, was es von der verzögerten Ausführung in Haskell unterscheidet
        Weniger knapp als die Stream-Version, zeigt aber klar monadische Prinzipien in einem nicht-funktionalen Sprachkontext.
    C#:
        C# nutzt für monadische Operationen die SelectMany-Methode, die eng mit der flatMap-Operation aus Java Streams verwandt ist.
		SelectMany erlaubt es, eine Funktion anzuwenden, die eine Sammlung für jedes Element zurückgibt, und vereint diese dann zu einer einzigen Liste. 
		Obwohl C# sofortige Ausführung verwendet und nicht auf kazy evcaluation wie Haskell setzt, ist der Ansatz doch funktional und passt gut in das Ökosystem der Sprache. 
		C# bietet eine syntaktisch elegante Möglichkeit, mit Monaden zu arbeiten, die einfacher ist als der explizite Ansatz von C++ oder der manuelle Ansatz von Java ohne Streams, aber dennoch nicht an die einfachheit und effizienz der Haskell Monade rankommt.
   
Quellen:
https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/nullable-value-types
https://learn.microsoft.com/en-us/dotnet/api/system.nullable-1
https://learn.microsoft.com/en-us/dotnet/api/system.linq
https://learn.microsoft.com/en-us/dotnet/api/system.linq.enumerable.selectmany
https://docs.oracle.com/javase/8/docs/api/java/util/Optional.html
https://docs.oracle.com/javase/8/docs/api/java/util/stream/Stream.html
https://en.cppreference.com/w/cpp/utility/optional
