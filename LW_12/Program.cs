using System;
using System.Diagnostics.Metrics;

namespace HelloApp
{
    class Vector
    {
        public float x { get; set; }
        public float y { get; set; }

        public float mod { get; set; }

        public Vector() : this(1.0f, 0.0f) {}

        public Vector(float x, float y)
        {
            this.x = x;
            this.y = y;

            mod = calcMod();

            if(mod != 1.0f)
            {
                this.x = x/mod;
                this.y = y / mod;
                mod = calcMod();
            }
        }

        public float calcMod()
        {
            return (float)Math.Sqrt(x * x + y * y);
        }

        public void toString()
        {
            Console.WriteLine($"X = {Math.Round(this.x, 1)}, Y = {Math.Round(this.y, 1)}\n");
        }

        public static Vector operator *(Vector c1, Vector c2)
        {
            float scalarProduct = c1.x * c2.x + c1.y * c2.y;
            Vector temp = new Vector {};
            temp.x = (float)Math.Round(temp.x * scalarProduct, 1);
            temp.y = (float)Math.Round(temp.y * scalarProduct, 1);

            return temp;
        }

    }



    class Program
    {
        static void Main(string[] args)
        {
            // виклик 1-го конструктора без параметрів
            Vector one = new Vector();
            Vector two = new Vector(1.2f, 2f);
            Vector three;

            one.toString();
            two.toString();

            Console.WriteLine("\n-----------------------------");
            Console.WriteLine("three = one * two");
            three = one * two;

            three.toString();

            Console.WriteLine("-----------------------------");

            Console.ReadKey();
        }
    }
}