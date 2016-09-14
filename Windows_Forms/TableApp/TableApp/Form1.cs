using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TableApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            dataGridView1.Rows.Add("Привет");
            dataGridView1.Rows.Add("О дивный");
            dataGridView1.Rows.Add("новый");
            dataGridView1.Rows.Add("мир");
            dataGridView1.Rows.Add("Ты");
            dataGridView1.Rows.Add("Прекрасен");
            dataGridView1.Rows.Add("как");
            dataGridView1.Rows.Add("1984");
            dataGridView1.Rows.Add("Оттенка");
            dataGridView1.Rows.Add("Пары");
            dataGridView1.Rows.Add("Сотен");
            dataGridView1.Rows.Add("Градусов");
            dataGridView1.Rows.Add("По");
            dataGridView1.Rows.Add("Фаренгейту");
            dataGridView1.Rows.Add("Пока");
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            var tmp = dataGridView1.Rows[e.RowIndex].Cells[0].Value;
            try
            {
                if (!string.IsNullOrWhiteSpace(tmp.ToString()))
                {
                    MessageBox.Show("Переносим ячейку: '" + tmp.ToString() + "' Из первой таблицы во вторую");
                    dataGridView2.Rows.Add(tmp);

                    DataGridViewCell selectedCell = dataGridView1.Rows[e.RowIndex].Cells[0];
                    selectedCell.Style.BackColor = Color.Aqua;

                    DataGridViewCell pressedButton = dataGridView1.Rows[e.RowIndex].Cells[1];
                }
            }
            catch(System.NullReferenceException)
            {
                return;
            }
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            var tmp = dataGridView2.Rows[e.RowIndex].Cells[0].Value;
            try
            {
                if (!string.IsNullOrWhiteSpace(tmp.ToString()))
                {
                    MessageBox.Show("Переносим ячейку: '" + tmp.ToString() + "' Из второй таблицы в первую");
                    dataGridView1.Rows.Add(tmp);

                    DataGridViewCell selectedCell = dataGridView2.Rows[e.RowIndex].Cells[0];
                    selectedCell.Style.BackColor = Color.Aqua;
                }
            }
            catch (System.NullReferenceException)
            {
                return;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataGridViewSelectedCellCollection selectedColumnCount = dataGridView1.SelectedCells;
            foreach(DataGridViewCell cell in selectedColumnCount)
            {
                if (cell.ColumnIndex == 0)
                {
                    try
                    {
                        if (!string.IsNullOrWhiteSpace(cell.Value.ToString()))
                        {
                            MessageBox.Show("Переносим ячейку: '" + cell.Value.ToString() + "' Из второй таблицы в первую");
                            dataGridView2.Rows.Add(dataGridView1.Rows[cell.RowIndex].Cells[0].Value);

                            DataGridViewCell selectedCell = dataGridView1.Rows[cell.RowIndex].Cells[0];
                            selectedCell.Style.BackColor = Color.Aqua;
                        }
                    }
                    catch (System.NullReferenceException)
                    {
                        return;
                    }
                }
            }
     
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DataGridViewSelectedCellCollection selectedColumnCount = dataGridView2.SelectedCells;
            foreach (DataGridViewCell cell in selectedColumnCount)
            {
                if (cell.ColumnIndex == 0)
                {
                    try
                    {
                        if (!string.IsNullOrWhiteSpace(cell.Value.ToString()))
                        {
                            MessageBox.Show("Переносим ячейку: '" + cell.Value.ToString() + "' Из второй таблицы в первую");
                            dataGridView1.Rows.Add(dataGridView2.Rows[cell.RowIndex].Cells[0].Value);

                            DataGridViewCell selectedCell = dataGridView2.Rows[cell.RowIndex].Cells[0];
                            selectedCell.Style.BackColor = Color.Aqua;
                        }
                    }
                    catch (System.NullReferenceException)
                    {
                        return;
                    }
                }
            }
        }
    }
}
