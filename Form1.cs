
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
using System.Windows.Forms.DataVisualization.Charting;

namespace  Temp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            Cursor = Cursors.WaitCursor;
            try
            {
                var inputs = new List<string>();

                foreach (var textBox in Controls.OfType<TextBox>())
                {
                    inputs.Add(textBox.Text);
                }
                // проверка заполнения полей
                if (inputs.Any(string.IsNullOrEmpty))
                {
                    MessageBox.Show("Не всі поля заповнені");
                }
                else
                {
                    var a = Convert.ToDouble(textBox1.Text);
                    var b = Convert.ToDouble(textBox2.Text);

                    // проверка нижней и верхней границы
                    if (a > b)
                    {
                        var tmp = a;
                        a = b;
                        b = tmp;
                    }
                    // підключення усіх графіків
                    Series graphic1 = chart1.Series["Вариант№14"];
                    Series graphic2 = chart1.Series["y = log(x)"];
                    Series graphic3 = chart1.Series["from file"];
                    // очистка
                    graphic1.Points.Clear();
                    graphic2.Points.Clear();
                    graphic3.Points.Clear();

                    if (checkBox1.Checked)
                    {
                        for (var i = a; i <= b; i += 0.1)
                        {
                            var x = i;
                            var y = Function(x);
                            graphic1.Points.AddXY(x, y);
                        }
                    }
                    if (checkBox2.Checked)
                    {
                        for (var i = a; i <= b; i += 0.1)
                        {
                            var x = i;
                            var y = Log(x);
                            graphic2.Points.AddXY(x, y);
                        }
                    }
                    if (checkBox3.Checked)
                    {
                        // считываем инф из файла в виде массива строк
                        var fileContent = File.ReadAllLines(@"c:/temp/test.txt");
                        // разделяем стоку х и у
                        var stringOfX = fileContent[0];
                        var stringOfY = fileContent[1];
                        // разделяем каждую строку через пробелы
                        var listOfX = stringOfX.Split(' ');
                        var listOfY = stringOfY.Split(' ');
                        // преобразование каждого х и у в double
                        for (var i = 0; i < listOfX.Length; i++)
                        {
                            var x = Convert.ToDouble(listOfX[i]);
                            var y = Convert.ToDouble(listOfY[i]);

                            graphic3.Points.AddXY(x, y);
                        }
                    }
                }
            }
            catch
            {

            }
            Cursor = Cursors.Default;
        }
        // індивідуальне завдання
        public double Function(double x)
        {
            try
            {
                if (x == 0.0)
                {
                    return 0;
                }
                else if (x > -3 && x <= 2)
                {
                    return Math.Pow(x, -2);
                }
                else if (x > 5 && x < 10)
                {
                    return Math.Pow(Math.Exp(-2 + x), 1 / 5) * (1 / Math.Sqrt(Math.Pow(x, 2) + x + Math.Log(Math.Abs(x - 3.14))));
                }
                else
                {
                    return Math.Pow(x, 2);
                }
            }
            catch
            {
                return 0;
            }
        }

        public double Log(double x)
        {
            return Math.Log(x);
        }
        
                        

           
        private void comboBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            // преобразование объекта типа object к типу combobox
            var comboBox = (ComboBox)sender;
            // достать выбраный елемент
            var selectedType = comboBox.SelectedItem.ToString();
            // пройтись по всем графикам
            foreach (var series in chart1.Series)
            {
                switch (selectedType)
                {
                    case "Line":
                        {
                            series.ChartType = SeriesChartType.Line;
                            break;
                        }
                    case "Point":
                        {
                            series.ChartType = SeriesChartType.Point;
                            break;
                        }
                }
            }
        }
       

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        // подсоединяем кнопку генерации файла с кодом для файла
        private void button1_Click_1(object sender, EventArgs e)
        {
            try
            {
                var a = Convert.ToDouble(textBox1.Text);
                var b = Convert.ToDouble(textBox2.Text);

                var childForm = new Form2
                {
                    A = a,
                    B = b
                };
                childForm.Show();
            }
            catch
            {

            }
        }

            // подсоединяем кнопку "Про програму" з кодом


            private void проПрограммуToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var about = new AboutProgramm();

            about.Show();
        }

       
        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
} 







