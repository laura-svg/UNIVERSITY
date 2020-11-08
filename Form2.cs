using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Temp
{
    public partial class Form2 : Form
    {
        public double A;
        public double B;

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
           
       

        private void button1_Click_1(object sender, EventArgs e)
        { 
          // взводимсчетчик
            var random = new Random();//srand(time(0))


        var inputs = new List<string>();

            // собираем все inputs
            foreach (var textBox in Controls.OfType<TextBox>())
            {
                inputs.Add(textBox.Text);
            }
            // проверяем на заполненость
            if (inputs.Any(string.IsNullOrEmpty))
            {
                MessageBox.Show("Не всі поля заповнені");
            }
            else
            {
                var countOfPoint = Convert.ToInt32(textBox1.Text);
                    var lowerBorder = Convert.ToInt32(textBox2.Text);
                    var upperBorder = Convert.ToInt32(textBox3.Text);

                if (countOfPoint< 0)
                {
                    countOfPoint = Math.Abs(countOfPoint);
                }

                if (lowerBorder > upperBorder)
                {
                    var tmp = lowerBorder;
                        lowerBorder = upperBorder;
                    upperBorder = tmp;
                }
                // создать пустые списки чисел для х и у
                var listOfX = new List<double>();
                        var listOfY = new List<int>();
                            // считаем шаг
                            var step = (B - A) / (countOfPoint - 1);
                // перемещаемся от нижнего значения до верхнего с шагом
                for (var i = A; i <= B; i += step)
                {

                    listOfX.Add(i);
                    // у - рандомное число, сгенерированное на заданом диапазоне
                    var y = lowerBorder + RandomNumber(random, 0, (upperBorder - lowerBorder));
                        listOfY.Add(y);
                }

                // удаляем старый файл  
                File.Delete(@"c:/temp/test.txt");
                // создаем новый
             var file = File.CreateText(@"c:/temp/test.txt");

                        // список х и у, разделенных пробелами
                          file.WriteLine(string.Join(" ", listOfX));
                file.WriteLine(string.Join(" ", listOfY));
                // закрыть файл для записи
                file.Close();

                Close();
            }
        }

        public int RandomNumber(Random random, int min, int max)
        {
            // рандомное число в заданом диапазоне
            return random.Next(min, max);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

    

