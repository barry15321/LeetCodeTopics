  public class Carry17
    {
        public void CarryCalculate()
        {

            int value = 973730151;
            List<int> stack = new List<int>();

            while (value > 0)
            {
                stack.Add(value % 17);
                value /= 17;
            }

            string Carry_17 = string.Empty;
            for (int i = stack.Count - 1; i >= 0; i--)
            {
                if (stack[i] > 9)                
                    Carry_17 += Convert.ToChar('A' + (stack[i] - 10));
                else
                    Carry_17 += stack[i];

                //Carry_17 += (stack[i] > 9) ? Convert.ToChar('A' + (stack[i] - 10)) : stack[i]; // the result show differently , why-_-

            }

            Console.WriteLine(Carry_17);
        }

    }