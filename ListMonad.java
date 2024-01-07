import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class MonadicList<T> {
    private List<T> list;

    public MonadicList() {
        this.list = new ArrayList<>();
    }

    public MonadicList(T value) {
        this();
        this.list.add(value);
    }

    public MonadicList(List<T> list) {
        this.list = new ArrayList<>(list);
    }

    public void pushBack(T element) {
        list.add(element);
    }

    public <S> MonadicList<S> mBind(Function<T, MonadicList<S>> f) {
        MonadicList<S> result = new MonadicList<>();
        for (T item : list) {
            MonadicList<S> temp = f.apply(item);
            for (S val : temp.getList()) {
                result.pushBack(val);
            }
        }
        return result;
    }

    public void print() {
        for (T element : list) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public List<T> getList() {
        return list;
    }

    public static void main(String[] args) {
        Function<Integer, MonadicList<Integer>> squareAndCube = n -> {
            MonadicList<Integer> result = new MonadicList<>();
            result.pushBack(n);
            result.pushBack(n * n);
            result.pushBack(n * n * n);
            return result;
        };

        MonadicList<Integer> myList = new MonadicList<>(2);
        MonadicList<Integer> resList = myList.mBind(squareAndCube).mBind(squareAndCube);
        resList.print();
        // Add code to use resList as needed
    }
}
