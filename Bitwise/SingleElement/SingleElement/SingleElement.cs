using System;

namespace SingleElement
{
    public static class SingleElement
    {
        public static int FindSingleElement(int[] array)
        {
            int ones = 0;
            int twos = 0;
            int commonBits = 0;

            for(int i = 0; i < array.Length; ++i)
            {
                twos = twos | (ones & array[i]);

                ones = ones ^ array[i];

                commonBits = ~(ones & twos);

                ones = ones & commonBits;
                twos = twos & commonBits;
            }

            return ones;
        }
    }
}
