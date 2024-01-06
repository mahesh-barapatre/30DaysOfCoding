class Solution
{
public:
    int givepower(int multiple)
    {
        int ans = 0;
        // int multiple = 1;
        // for (int i = a; i <= b; i++)
        // {
        //     multiple *= i;
        // }

        while (multiple % 2 == 0)
        {

            multiple = multiple / 2;
            ans += 1;
        }
        for (int j = 3; j <= sqrt(multiple); j += 2)
        {
            int power = 0;
            while (multiple % j == 0)
            {

                multiple = multiple / j;
                power++;
            }
            ans += power;
        }
        if (multiple > 2)
            ans += 1;

        return ans;
    }

    int sumOfPowers(int a, int b)
    {
        // Code here
        int power = 0;
        for (int i = a; i <= b; i++)
        {
            power += givepower(i);
        }

        return power;
    }
};