using System;
namespace HelloApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter:\n\t1\tfor first task\n\t2\tfor second task\n");
            int choose = Convert.ToInt32(Console.ReadLine());

            switch (choose)
            {
                case 1:
                    firstTask(); 
                    break;
                case 2:
                    secondTask();
                    break;
            }

        Console.ReadKey();
        }

        public static void firstTask()
        {
            int x, y, z;
            string result1;

            while (true)
            {
                Console.Write("\nEnter x:");
                x = Convert.ToInt32(Console.ReadLine());
                if(x == 0) { Environment.Exit(0); }
                result1 = (x < -10) ? "Less then -10" : (x < -1) ? "Less then -1" : (x > 10) ? "Bigger then 10" : "Bigger then 1";

                Console.Write("Enter y:");
                y = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter z:");
                z = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine($"\nYour x is:\t{result1}\n");
                float result = (float)Math.Round(Math.Sqrt(x * x * x + y * y + z), 2);
                result1 = (result >= 0) ? "Positive" : "Negative";

                Console.WriteLine($"Your result is:\t{result}\t{result1}");
            }            
        }

        public static void secondTask()
        {
            const double x1 = 8.5, y1 = 2.4, z1 = 4.1;

            Console.WriteLine($"\nAll products cost:\t{x1+y1+z1}$");

            Console.WriteLine($"\nButter + sour cream =\t{x1 + y1}$");
            Console.WriteLine($"Butter + cream =\t{x1 + z1}$");
            Console.WriteLine($"Cream + sour cream =\t{z1 + y1}$");

        }
    }
}
