#include <iostream>

using namespace std;

float powerbin(float x, int n)
{
    if (n == 0) return 1;
    if (n % 2)
        return powerbin(x, n - 1) * x;
    else
    {
        float power = powerbin(x, n / 2);
        return power * power;
    }
}

int main()
{
    /*
    srand(time(nullptr));

    int N{ 10 };
    int* array = new int[N];

    for (int i = 0; i < N; i++)
        array[i] = rand() % 100;

    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << "\n";

    int maxAmount{ array[0] };
    int maxIndex{};
    for (int i = 0; i < N / 2 + 1; i++)
    {
        int amount{};
        cout << i << " : ";
        for (int j = i; j < i + N / 2; j++)
        {
            cout << array[j] << " ";
            amount += array[j];
        }
        cout << " => " << amount << "\n";
            
        if (maxAmount < amount)
        {
            maxAmount = amount;
            maxIndex = i;
        }
    }

    cout << "\n" << maxIndex << " " << maxAmount << "\n\n";

    maxAmount = array[0];

    maxIndex = 0;
    int amount{};
    for (int i = 0; i < N / 2; i++)
        amount += array[i];
    cout << 0 << " => " << amount << "\n";
    
    
    for (int i = 1; i < N / 2 + 1; i++)
    {
        amount = amount - array[i - 1] + array[i + N / 2 - 1];
        cout << i << " => " << amount << "\n";
        if (amount > maxAmount)
        {
            maxAmount = amount;
            maxIndex = i;
        }
    }
    cout << "\n" << maxIndex << " " << maxAmount << "\n\n";
    */

    /*
    int max = array[0];
    for (int i = 1; i < N; i++)
        if (max < array[i])
            max = array[i];
    */
    /*
    for (int i = 0; i < N; i++)
    {
        for(int j = N - 1; j > i; j--)
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
    }
    */

    float x{ 3.5 };
    int n{ 5 };
    float power{ 1.};

    for (int i = 0; i < n; i++)
        power *= x;
    cout << "O(N) = N : " << power << "\n";
    
    power = 1;
    int ncopy = n;
    float xcopy = x;

    while (n)
    {
        if (n % 2)
        {
            power *= x;
            n--;
        }
        else
        {
            x *= x;
            n /= 2;
        }
    }
    cout << "O(N) = logN : " << power << "\n";

    power = 1;
    n = ncopy;
    x = xcopy;

    while (n)
    {
        if (n % 2)
            power *= x;
        x *= x;
        n /= 2;
    }
    cout << "O(N) = logN : " << power << "\n";

    cout << "O(N) = logN : " << powerbin(xcopy, ncopy) << "\n";
}
