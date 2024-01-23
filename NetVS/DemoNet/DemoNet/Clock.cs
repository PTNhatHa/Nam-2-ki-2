using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace DemoNet
{
    internal class Clock //lớp phát sinh sự kiện
    {
        public delegate void SecondHandler(object o, TimeEventArgs e);
        public event SecondHandler OnSecondChange;
        public void Run()
        {
            while (true)
            {
                Thread.Sleep(1000);
                if(OnSecondChange != null)
                {
                    OnSecondChange(this, new TimeEventArgs
                    {
                        Timer = DateTime.Now
                    });
                }
            }
        }
    }
}
