using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Stock
{
    public class StockBroker
    {
        public string BrokerName { get; set; }

        public List<Stock> stocks = new List<Stock>();

        readonly string destPath =
            Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Lab1_Output.txt");

        public string titles =
            "Broker".PadRight(10) +
            "Stock".PadRight(15) +
            "Value".PadRight(10) +
            "Changes".PadRight(10) +
            "Date and Time";

        public StockBroker(string brokerName)
        {
            BrokerName = brokerName;

            Console.WriteLine(titles);

            using (StreamWriter outputFile = new StreamWriter(destPath, false))
            {
                outputFile.WriteLine(titles);
            }
        }

        public void AddStock(Stock stock)
        {
            stocks.Add(stock);
            stock.StockEvent += EventHandler;
        }

        public async void EventHandler(object? sender, StockNotification e)
        {
            await write(sender, e);
        }

        public async Task write(object? sender, StockNotification e)
        {
            String line =
                BrokerName.PadRight(10) +
                e.StockName.PadRight(15) +
                Convert.ToString(e.CurrentValue).PadRight(10) +
                Convert.ToString(e.NumChanges).PadRight(10) +
                DateTime.Now;

            try
            {
                Console.WriteLine(line);

                using (StreamWriter outputFile = new StreamWriter(destPath, true))
                {
                    await outputFile.WriteLineAsync(line);
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine($"Error writing to file: {ex.Message}");
            }
        }
    }
}
