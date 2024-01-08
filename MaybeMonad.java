import java.util.Optional;

public class MaybeMonad {

    public static Optional<Integer> divSafe(int n, int m) {
        if (m == 0) {
            return Optional.empty();
        } else {
            return Optional.of(n / m);
        }
    }

    public static Optional<Integer> exampleM(int x, int y, int z) {
        return divSafe(x, y)
            .flatMap(res -> divSafe(res, z));
    }

    public static void main(String[] args) {
        int x = 12;
        int y = 2;
        int z = 3;

        Optional<Integer> result = exampleM(x, y, z);
        result.ifPresent(System.out::println);
    }
}
