using System.Text.Json;
using HolidaysViewers.Models;

namespace HolidaysViewers.Services
{
    public class HolidaysApiService : IHolidaysApiService
    {
        private static readonly HttpClient client;

        static HolidaysApiService()
        {
            client = new HttpClient
            {
                BaseAddress = new Uri("https://date.nager.at")
            };
        }

        public async Task<List<HolidayModel>> GetHolidaysAsync(string countryCode, int year)
        {
            if (string.IsNullOrWhiteSpace(countryCode))
            {
                throw new ArgumentException("Country code is required.");
            }

            if (year < 1)
            {
                throw new ArgumentException("Year must be valid.");
            }

            string url = $"/api/v3/PublicHolidays/{year}/{countryCode.Trim().ToUpper()}";
            using HttpResponseMessage response = await client.GetAsync(url);

            if (!response.IsSuccessStatusCode)
            {
                throw new HttpRequestException($"API request failed: {(int)response.StatusCode} {response.ReasonPhrase}");
            }

            string json = await response.Content.ReadAsStringAsync();
            var holidays = JsonSerializer.Deserialize<List<HolidayModel>>(
                json,
                new JsonSerializerOptions
                {
                    PropertyNameCaseInsensitive = true
                });

            return holidays ?? new List<HolidayModel>();
        }
    }
}
