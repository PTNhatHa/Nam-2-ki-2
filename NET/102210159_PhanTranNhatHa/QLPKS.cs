using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace QLKS
{
    public class QLPKS
    {
        private PhongKS[] data;
        private int _Count;
        public int Count
        {
            get;
            private set;
        }
        private static QLPKS _Instance;
        public static QLPKS Instance
        {
            get
            {
                if(_Instance==null)
                {
                    _Instance = new QLPKS;
                }
                return _Instance;
            }
            private set {}
        }
        private QLPKS()
        {
            this.data = null;
            this._Count = 0;
        }
        public void Add(PhongKS p)
        {
            data[_Count] = p;
            _Count++;
        }
        public void AddRange(params PhongKS[] p)
        {
            for(int i=0; i<p.Length; i++)
            {
                data[_Count] = p[i];
                _Count++;
            }
        }
        public int IndexOf(PhongKS p)
        {
            for (int i = 0; i < _Count; i++)
            {
                if (data[i]==p) return i;
            }
            return -1;
        }
        public void RemoveAt(int index)
        {
            for (int i = index; i < _Count; i++)
            {
                data[i]=data[i+1];
            }
            _Count--;
        }
        public void RemoveRange(int index, int range)
        {
            for (int i = index; i < _Count; i++)
            {
                data[i]=data[i+range];
            }
            _Count=_Count-range;
        }
        public override string ToString()
        {
            
        }
        public void Show()
        {
            for (int i = 0; i < _Count; i++)
            {
                data[i].Show();
            }
        }
        public void Sort()
        {

        }
        public void Update()
        {
            
        }
    }
}