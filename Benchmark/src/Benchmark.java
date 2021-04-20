import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.stream.IntStream;

public class Benchmark {
    static int[] generate_random_arr(int size) {
        Random r = new Random();
        return IntStream.generate(r::nextInt).limit(size).toArray();
    }

    static double summarize(int[] arr) {
        long startTime = System.nanoTime();
        long sum = 0;
        for (int j : arr) {
            sum += j;
        }
        double time =(double)(System.nanoTime() - startTime)/1e+9;
        if (sum==0)
            throw new IllegalStateException();
        return time;
    }

    static double summarize_if(int[] arr) {
        long startTime = System.nanoTime();
        long sum = 0;
        for (int j : arr) {
            if (j > 1073741823)
                sum += j;
        }
        double time =(double)(System.nanoTime() - startTime)/1e+9;
        if (sum==0)
            throw new IllegalStateException();
        return time;
    }

    static double no_duplicate(int[] arr) {
        long startTime = System.nanoTime();
        HashSet<Integer> integerHashSet= new HashSet<>();
        for (int j : arr) {
            integerHashSet.add(j);
        }
        double time =(double)(System.nanoTime() - startTime)/1e+9;
        if (integerHashSet.size()==0)
            throw new IllegalStateException();
        return time;
    }

    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            int[] long_benchmark = generate_random_arr(100000000);
            System.out.printf("java_summarize,%.10f\n",summarize(long_benchmark));
        }


        for (int i = 0; i < 100; i++) {
            int[] benchmark_data = generate_random_arr(1000000);
            System.out.printf("java_summarize_if,%.10f\n",summarize_if(benchmark_data));
        }

        for (int i = 0; i < 100; i++) {
            int[] benchmark_data = generate_random_arr(1000000);
            System.out.printf("java_no_duplicate,%.10f\n",no_duplicate(benchmark_data));
        }
    }
}