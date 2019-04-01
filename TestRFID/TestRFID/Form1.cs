using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestRFID
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            String codigo="";
            String rfid = "";

            for (int i = 0; i < 3; i++) {           
                rfid= serialPort1.ReadLine();
                codigo = codigo +"\t"+rfid;
                txtCod.Text = codigo;
            }
            
            serialPort1.Close();
        }
    }
}
