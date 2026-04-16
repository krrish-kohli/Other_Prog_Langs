# HolidaysViewers

ASP.NET Core MVC app that fetches public holidays from the Nager.Date API.

## Requirements

On Arch Linux, install the packages needed for ASP.NET Core apps:

```bash
sudo pacman -S dotnet-sdk aspnet-runtime aspnet-targeting-pack
```

Check your installation:

```bash
dotnet --list-sdks
dotnet --list-runtimes
```

You should see .NET 10 and Microsoft.AspNetCore.App 10.x.

## Run the project

From the `HolidaysViewers` folder:

```bash
rm -rf bin obj
dotnet restore
dotnet build
dotnet run
```

Then open the local URL shown in the terminal.

## Pages

- `/Home/Index` - Part I MVC version
- `/Home/Ajax` - Part II AJAX version

## Test input

- Country Code: `US`
- Year: `2025`

## Notes for Arch Linux

If restore shows `NETSDK1226: Prune Package data not found`, the project file already enables:

```xml
<AllowMissingPrunePackageData>true</AllowMissingPrunePackageData>
```

If build still fails, install the ASP.NET Core targeting pack:

```bash
sudo pacman -S aspnet-targeting-pack
```
