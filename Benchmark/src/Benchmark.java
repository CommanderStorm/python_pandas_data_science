import java.util.Arrays;
import java.util.List;
import java.util.HashSet;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Benchmark {
    static int[] generate_random_arr(int size) {
        Random r = new Random();
        return IntStream.generate(r::nextInt).filter(x->x>=0).limit(size).toArray();
    }

    static double summarise(int[] arr) {
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

    static double summarise_if(int[] arr) {
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
        List<Integer> int_list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        long startTime = System.nanoTime();
        HashSet<Integer> integerHashSet= new HashSet<>(int_list);
        double time =(double)(System.nanoTime() - startTime)/1e+9;
        if (integerHashSet.size()==0)
            throw new IllegalStateException();
        return time;
    }

    public static void main(String[] args) {
        for (int benchmark_cnt = 25_000_000; benchmark_cnt < 1_000_000_000; benchmark_cnt+=25_000_000) {
            for (int i = 0; i < 20; i++) {
                int[] long_benchmark = generate_random_arr(benchmark_cnt);
                System.out.printf("java_summarise,%d,%.10f\n",benchmark_cnt,summarise(long_benchmark));
            }


            for (int i = 0; i < 20; i++) {
                int[] benchmark_data = generate_random_arr(benchmark_cnt);
                System.out.printf("java_summarise_if,%d,%.10f\n",benchmark_cnt,summarise_if(benchmark_data));
            }
        } 
        for (int benchmark_cnt = 100_000; benchmark_cnt < 10_000_000; benchmark_cnt+=100_000) {
            for (int i = 0; i < 20; i++) {
                int[] benchmark_data = generate_random_arr(benchmark_cnt);
                System.out.printf("java_no_duplicate,%d,%.10f\n",benchmark_cnt,no_duplicate(benchmark_data));
            }
        }
    }
}