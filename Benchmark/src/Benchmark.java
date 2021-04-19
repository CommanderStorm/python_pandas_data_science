import java.util.Arrays;
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
        return (double)(System.currentTimeMillis() - startTime)/1000;
    }

    static double sum_if(int[] arr) {
        long startTime = System.currentTimeMillis();
        long sum = 0;
        for (int j : arr) {
            if (j > 1073741823)
                sum += j;
        }
        return (double)(System.currentTimeMillis() - startTime)/1000;
    }

    static double no_duplicate(int[] arr) {
        long startTime = System.currentTimeMillis();
        int len = 1000000;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] == arr[j]) {
                    System.arraycopy(arr, j + 1, arr, j, len - j - 1);
                    j--;
                    len--;
                }
            }
        }
        return (double)(System.currentTimeMillis() - startTime)/1000;
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