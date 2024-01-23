using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DemoNet
{
    internal class TimeEventArgs : EventArgs
    {
        public DateTime Timer { get; set; }
    }
}
