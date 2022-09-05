namespace Delegates_1
{
    delegate double calc(double x);

    // оголошення делегата, на основі якого буде визначено подію
    delegate void MyEventHandler(ConsoleKeyInfo k);
    // оголошення класу, в якому ініціюється подія
    class MyClassWithEvent
    {
        public event MyEventHandler AnyKeyPress; // оголошення події
                                                 // в цьому методі ініціюється подія
        public void fire()
        {
            if (AnyKeyPress != null)
            {
                ConsoleKeyInfo k = Console.ReadKey(true);
                AnyKeyPress(k);
            }
        }
    }

    class Program
    {
        static void handler(ConsoleKeyInfo k)
        {
            char c = k.KeyChar;
            if(c == 'v' || c == 'V') 
                Console.WriteLine($"Vlad, pressed '{c}'");
        }

        static double F1(double x)
        {
            if (x < 0) x *= -1;
            return 1/(Math.Sqrt(x));
        }
        static double F2(double x)
        {
            return 1 / (x*x + 1);
        }
        static double F3(double x)
        {
            return x*x*x + x*x + x + 1;
        }

        static double Trap(calc q, double a, double b)
        {
            int N, i;
            double x, dx, sum;
            sum = 0;
            N = 90;
            dx = (b - a) / N;
            for (i = 0, x = a; i < N; i++)
            {
                sum += (q(x) + q(x + dx)) / 2 * dx;
                x += dx;
            }
            // Геометричний сенс визначеного інтеграла-це площа під кривою
            // якщо в задачі потрібно розрахувати саме її,
            // то вона звичайно позитивна, але якщо ми просто шукаємо певний інтеграл для функції,
            // яка негативна на отрезке, то результат може бути негативним.
            // Якщо крива розташування нижче осі Х, то отримаємо від’ємне значення
            return sum;
        }


        static void Main(string[] args)
        {
            double a, b, i;
            a = 0; b = 1; // low and high limit of the integral

            int firstX = -1;
            int seconfX = 1;
            int thirthX = 1;

            calc q = new calc(F1);
            i = q(firstX);
            Console.WriteLine(Trap(q, a, b));

            q = new calc(F2);
            i = q(seconfX);
            Console.WriteLine(Trap(q, a, b));

            q = new calc(F3);
            i = q(thirthX);
            Console.WriteLine(Trap(q, a, b));

            Console.ReadLine();

            MyClassWithEvent evt = new MyClassWithEvent(); // створення екземпляра класу, в якому ініціюється подія
            // додавання методу handler до ланцюжку обробників події
            evt.AnyKeyPress += new MyEventHandler(handler);
            // ініціювання події
            evt.fire();

            Console.ReadLine();
        }
        

    }
}
