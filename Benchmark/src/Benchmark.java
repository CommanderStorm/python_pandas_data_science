import java.util.Arrays;
import java.util.HashSet;
import java.util.Random;
import java.util.stream.IntStream;

public class Benchmark {
    static int[] generate_random_arr(int size) {
        Random r = new Random();
        return IntStream.generate(r::nextInt).filter(x->x>=0).limit(size).toArray();
    }

    static double summarize(int[] arr) {
        long startTime = System.nanoTime();
        long sum = 0;
        for (int j : arr) {
            sum += j;
        }
        double time =(double)(System.nanoTime() - startTime)/1e+9;
        if (sum<0)
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
        if (sum<0)
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
        if (integerHashSet.size()<0)
            throw new IllegalStateException();
        return time;
    }

    public static void main(String[] args) {
        for (int benchmark_cnt = 100_0000; benchmark_cnt < 10_000_000; benchmark_cnt+=100_0000) {
            for (int i = 0; i < 20; i++) {
                int[] long_benchmark = generate_random_arr(benchmark_cnt);
                System.out.printf("java_summarize,%d,%.10f\n",benchmark_cnt,summarize(long_benchmark));
            }


            for (int i = 0; i < 20; i++) {
                int[] benchmark_data = generate_random_arr(benchmark_cnt);
                System.out.printf("java_summarize_if,%d,%.10f\n",benchmark_cnt,summarize_if(benchmark_data));
            }

            for (int i = 0; i < 20; i++) {
                int[] benchmark_data = generate_random_arr(benchmark_cnt);
                System.out.printf("java_no_duplicate,%d,%.10f\n",benchmark_cnt,no_duplicate(benchmark_data));
            }
        }
    }
}