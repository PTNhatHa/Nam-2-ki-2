using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNet
{
    internal class AnalogClock
    {
        public void ShowAC(object o, TimeEventArgs e)
        {
            DateTime d = DateTime.Now;
            Console.WriteLine("AC: {0}:{1}:{2}:{3}",
                e.Timer.Hour, e.Timer.Minute, e.Timer.Second, e.Timer.Millisecond);
        }
    }
}
