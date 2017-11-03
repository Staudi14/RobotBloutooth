using System;
using System.Diagnostics;
using System.Windows.Forms;

namespace Robot
{
    public partial class Form1 : Form
    {
        public Stopwatch watch { get; set; }
        public Form1()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            watch = Stopwatch.StartNew();
            //Init Port
            sPort.Open();
        }

        private void trackBarLeft_Scroll(object sender, EventArgs e)
        {
            if(watch.ElapsedMilliseconds > 10)      //Make sure the uC is not overloaded!
            {
                watch.Reset();
                //Send Data for left motor
                byte[] b = new byte[1];
                b[0] = 0x40;
                b[0] |= (byte)(0x3F & trackBarRight.Value);
                sPort.Write(b, 0, 1);
            }
        }

        private void trackBarRight_Scroll(object sender, EventArgs e)
        {
            if (watch.ElapsedMilliseconds > 10)     //Make sure teh uC is not overloaded!
            {
                watch.Reset();
                //Send Data for Right motor
                byte[] b = new byte[1];
                b[0] = 0x80;
                b[0] |= (byte) (0x3F & trackBarRight.Value);
                sPort.Write(b, 0, 1);
            }
        }

        private void send_Click(object sender, EventArgs e)
        {
            sPort.Write(textBoxSend.Text);
        }
    }
}
