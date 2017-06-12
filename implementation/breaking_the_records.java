import java.util.Scanner;


class Solution{
  
  public static int[] getRecords(int[] values){
    int [] answer = new int[2];
    answer[0] = values[0];  // min values
    answer[1] = values[0];  // max values
    int count_min = 0, count_max = 0;
    for (int v : values){
      if (v < answer[0]){
        answer[0] = v;
        count_min++;
      }
      else if (v > answer[1]){
        answer[1] = v;
        count_max++;
      }
    }
    answer[0] = count_min;
    answer[1] = count_max;
    return answer;
  }

  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int [] values = new int[n];
    for (int i = 0; i < n; i++){
      values[i] = in.nextInt();
    }
    int [] records = getRecords(values);
    System.out.println(records[1] + " " + records[0]);
  }
}
