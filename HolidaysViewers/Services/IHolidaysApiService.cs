using HolidaysViewers.Models;

namespace HolidaysViewers.Services
{
    public interface IHolidaysApiService
    {
        Task<List<HolidayModel>> GetHolidaysAsync(string countryCode, int year);
    }
}
