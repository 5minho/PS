/**
 * IDE : IntelliJ IDEA
 * Created by minho on 2018. 3. 17..
 */
public class BinaryGap {
    public int solution(int N) {
        int count = 0;
        int answer = 0;

        if ((N & 1) == 0) {
            while (((N >>= 1) & 1) != 1);
        }

        for (; N > 0 ; N >>= 1) {
            if ((N & 1) == 0) {
                count += 1;
                answer = Math.max(count,answer);
                continue;
            }
            count = 0;
        }
        return answer;
    }

}
