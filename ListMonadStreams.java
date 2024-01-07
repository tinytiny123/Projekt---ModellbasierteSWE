import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StreamMonadExample {
    public static void main(String[] args) {
        List<Integer> myList = Arrays.asList(2);

        List<Integer> resList = myList.stream()
                                      .flatMap(n -> squareAndCube(n).stream())
                                      .flatMap(n -> squareAndCube(n).stream())
                                      .collect(Collectors.toList());

        System.out.println(resList);
    }

    public static List<Integer> squareAndCube(int n) {
        return Arrays.asList(n, n * n, n * n * n);
    }
}
