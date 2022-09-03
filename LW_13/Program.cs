class Program
{
    abstract class Music
    {
        protected string Name { get; set; }
        protected int Minutes { get; set; }
        protected int Seconds { get; set; }
        
        public virtual void display()
        {
            Console.WriteLine($"{Name}, duration: {Minutes}:{Seconds}");
        }

        public int getTimeInSec()
        { 
            return (int)(Minutes * 60 + Seconds);
        }
    }

    class MusicGenre : Music
    {
        protected string NameOfGenre { get; set; }

        public MusicGenre(string nameOfGenre, string Name, int Min , int Sec)
        {
            this.NameOfGenre = nameOfGenre;
            this.Name = Name;
            this.Minutes = Min;
            this.Seconds = Sec;
        }
        public override void display()
        {
            Console.WriteLine($"{Name}, duration: {Minutes}:{Seconds}\n\tGenre = {NameOfGenre}");
        }

    }

    class MusicGenre2 : MusicGenre
    {
        protected string NameOfGenre2 { get; set; }

        public MusicGenre2(string NameOfGenre2, string nameOfGenre, string Name, int Min, int Sec) : base(nameOfGenre, Name, Min, Sec)
        {
            this.NameOfGenre2 = NameOfGenre2;
            this.NameOfGenre = nameOfGenre;
            this.Name = Name;
            this.Minutes = Min;
            this.Seconds = Sec;
        }
        public override void display()
        {
            Console.WriteLine($"{Name}, duration: {Minutes}:{Seconds}\n\tGenre = {NameOfGenre}, Genre2 = {NameOfGenre2}");
        }

    }


    static void Main(string[] args)
    {
        int timeMusicSec = 0;
        List<Music> music = new List<Music>
        {
            new MusicGenre("Rock", "Hell", 2, 30),
            new MusicGenre2("HardRock", "Rock", "HELL2", 1, 0)
        }; // Створюємо список покажчиків на базовий клас

        foreach (Music musics in music)
        {
            musics.display();
            timeMusicSec += musics.getTimeInSec();
        }

        int timeMusicMin = timeMusicSec / 60;
        timeMusicSec -= timeMusicMin * 60;
        Console.WriteLine($"\nDuration of all list is:\t{timeMusicMin}:{timeMusicSec}");
       
        Console.ReadKey();
    }
}