import java.util.*;

public class CharFrequency{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string: ");
        String str = sc.nextLine();

        HashMap<Character, Integer> map = new HashMap<>();
        for(char ch : str.toCharArray()){
            if(map.containsKey(ch))
                map.put(ch, map.get(ch) + 1);
            else
                map.put(ch, 1);
        }

        System.out.println(map);
    }
}
