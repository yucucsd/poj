import java.util.Scanner;

public class Main {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int[] ans = new int[15];
		//System.out.printf("k = %d\n", k);
		while (k != 0)
		{
			int m = k + 1;
			while (ans[k] == 0)
			{
				boolean kill_good_guy = false;
				int kill = 0;
				for (int i = 0; i < k; i++)
				{
					kill = (kill + m - 1) % (2 * k - i);
					//System.out.printf("m = %d, kill = %d\n", m, kill);
					if (kill < k)
					{
						kill_good_guy = true;
						break;
					}
					
				}
				if (!kill_good_guy)
				{
					ans[k] = m;
					//System.out.printf("ans = %d\n", m);
				}
				m++;
				//System.out.printf("m = %d\n", m);
			}
			System.out.printf("%d\n", ans[k]);
			k = sc.nextInt();
		}
		/*for (int i = 0; i < 14; i++)
		{
			System.out.printf("i = %d: m = %d\n", i, ans[i]);
		}*/
	}
}
