using HolidaysViewers.Models;
using HolidaysViewers.Services;
using Microsoft.AspNetCore.Mvc;

namespace HolidaysViewers.Controllers
{
    public class HomeController : Controller
    {
        private readonly IHolidaysApiService _holidaysApiService;

        public HomeController(IHolidaysApiService holidaysApiService)
        {
            _holidaysApiService = holidaysApiService;
        }

        [HttpGet]
        public async Task<IActionResult> Index(string? countryCode, int? year)
        {
            var vm = new HolidaysPageViewModel
            {
                CountryCode = countryCode ?? string.Empty,
                Year = year
            };

            if (string.IsNullOrWhiteSpace(countryCode) || !year.HasValue)
            {
                return View(vm);
            }

            try
            {
                vm.Holidays = await _holidaysApiService.GetHolidaysAsync(countryCode, year.Value);
            }
            catch (Exception ex)
            {
                vm.ErrorMessage = ex.Message;
            }

            return View(vm);
        }

        [HttpGet]
        public IActionResult Ajax()
        {
            return View();
        }

        [HttpGet]
        public async Task<IActionResult> GetHolidaysAjax(string countryCode, int year)
        {
            if (string.IsNullOrWhiteSpace(countryCode) || year <= 0)
            {
                return BadRequest(new { message = "Please enter a valid country code and year." });
            }

            try
            {
                var holidays = await _holidaysApiService.GetHolidaysAsync(countryCode, year);
                return Json(holidays);
            }
            catch (Exception ex)
            {
                return BadRequest(new { message = ex.Message });
            }
        }

        public IActionResult Privacy()
        {
            return View();
        }
    }
}
