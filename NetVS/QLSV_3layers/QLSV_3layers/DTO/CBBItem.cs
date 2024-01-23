using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QLSV_3layers.DTO
{
    internal class CBBItem
    {
        public int Value { get; set; } //ID
        public string Text { get; set; } //Name
        public override string ToString()
        {
            return Text;
        }
    }
}
