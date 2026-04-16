namespace HolidaysViewers.Models
{
    public class HolidayModel
    {
        public string Name { get; set; } = string.Empty;
        public string LocalName { get; set; } = string.Empty;
        public DateTime? Date { get; set; }
        public string CountryCode { get; set; } = string.Empty;
        public bool Global { get; set; }
    }
}
