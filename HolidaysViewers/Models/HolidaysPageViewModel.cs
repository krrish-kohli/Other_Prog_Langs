namespace HolidaysViewers.Models
{
    public class HolidaysPageViewModel
    {
        public string CountryCode { get; set; } = string.Empty;
        public int? Year { get; set; }
        public List<HolidayModel> Holidays { get; set; } = new();
        public string ErrorMessage { get; set; } = string.Empty;
    }
}
