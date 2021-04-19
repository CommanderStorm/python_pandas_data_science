import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.stream.IntStream;

public class Benchmark {
    static int[] generate_random_arr(int size) {
        Random r = new Random();
        return IntStream.generate(r::nextInt).limit(size).toArray();
    }

    static double sum(int[] arr) {
        long startTime = System.currentTimeMillis();
        long sum = 0;
        for (int j : arr) {
            if (j > 1073741823)
                sum += j;
        }
        double time =(double)(System.currentTimeMillis() - startTime)/1000;
        if (sum==0)
            throw new IllegalStateException();
        return time;
    }

    static double sum_if(int[] arr) {
        long startTime = System.currentTimeMillis();
        long sum = 0;
        for (int j : arr) {
            if (j > 1073741823)
                sum += j;
        }
        double time =(double)(System.currentTimeMillis() - startTime)/1000;
        if (sum==0)
            throw new IllegalStateException();
        return time;
    }

    static double no_duplicate(int[] arr) {
        long startTime = System.currentTimeMillis();
        HashSet<Integer> integerHashSet= new HashSet<>();
        for (int j : arr) {
            integerHashSet.add(j);
        }
        double time =(double)(System.currentTimeMillis() - startTime)/1000;
        if (integerHashSet.size()==0)
            throw new IllegalStateException();
        return time;
    }

    public static void main(String[] args) {
        int[] benchmark_data = generate_random_arr(1000000);
        int[] long_benchmark = generate_random_arr(100000000);
        double[][] results = new double[3][100];
        for (int i = 0; i < 100; i++) {
            results[0][i] = sum(long_benchmark);
        }
        for (int i = 0; i < 100; i++) {
            results[1][i] = sum_if(benchmark_data);
        }
        for (int i = 0; i < 100; i++) {
            results[2][i] = no_duplicate(benchmark_data);
        }
        System.out.println(Arrays.deepToString(results));
    }
}