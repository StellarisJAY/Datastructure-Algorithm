import java.util.Scanner;

public class MaxSubArraySum
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int size = Integer.parseInt(sc.nextLine());
        int[] list = new int[size];

        for(int i = 0; i < size; i++){
            list[i] = sc.nextInt();
        }
        System.out.println(maxSum(list, 0, size - 1));

        sc.close();
    }

    static int maxSum(int[] list, int left, int right)
    {
        int mid = (left + right) / 2;
        int leftMaxSum, rightMaxSum;
        int leftSideMaxSum = 0, rightSideMaxSum = 0, leftSideSum = 0, rightSideSum = 0;
        if(left == right){
            if(list[left] <= 0)return 0;
            else return list[left];
        }

        leftMaxSum = maxSum(list, left, mid);
        rightMaxSum = maxSum(list, mid + 1, right);

        for(int i = mid - 1; i >= left; i--){
            leftSideSum += list[i];
            if(leftSideSum > leftSideMaxSum)
                leftSideMaxSum = leftSideSum;
        }

        for(int j = mid + 1; j <= right; j++){
            rightSideSum += list[j];
            if(rightSideSum > rightSideMaxSum)
                rightSideMaxSum = rightSideSum;
        }
        System.out.println(leftSideMaxSum + " " + rightSideMaxSum + " " + (leftSideMaxSum + rightSideMaxSum + list[mid]));
        return max3(rightSideMaxSum + leftSideMaxSum + list[mid], rightMaxSum, leftMaxSum);

    }

    static int max3(int a, int b, int c)
    {
        int max = a;
        if(b > max)
            max = b;
        if(c > max)
            max = c;
        return max;
    }
}
