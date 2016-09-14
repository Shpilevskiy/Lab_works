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
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            var tmp = dataGridView1.Rows[e.RowIndex].Cells[0].Value;
            try
            {
                if (!String.IsNullOrWhiteSpace(tmp.ToString()))
                {
                    MessageBox.Show("Переносим колонку: '" + tmp.ToString() + "' Из первой таблицы во вторую");
                    dataGridView2.Rows.Add(tmp);
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
                if (!String.IsNullOrWhiteSpace(tmp.ToString()))
                {
                    MessageBox.Show("Переносим колонку: '" + tmp.ToString() + "' Из второй таблицы в первую");
                    dataGridView1.Rows.Add(tmp);
                }
            }
            catch (System.NullReferenceException)
            {
                return;
            }
        }
    }
}
