/* ALL POSSIBLE CONTIGIOUS SUBSTRINGS */
import java.util.HashSet;
import java.util.Scanner;

public class SubStrings {

    public static HashSet<String> arr = new HashSet<>();

    public static void subString(String s, int n) {
        if (n == 0)
            return;
        else if (n == 1) {
            arr.add(s);
            return;
        }
        int i = 0;
        int j = i + n - 1;
        while (j <= n - 1) {
            j = i + n - 1;
            arr.add(s.substring(i, j));
            subString(s.substring(i, j), n - 1);
            i++;
        }
    }

    public static void main(String[] args) {
        String s;
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter String : ");
        s = ip.nextLine();
        int n = s.length();
        arr.add(s);
        subString(s, n);
        for (String string : arr) {
            System.out.println(string);

        }
        System.out.println("\n Total No of Substrings are : " + arr.size());

    }
}
