using System;

namespace Validation
{
    public interface IValidatorData
    {
        bool ValidatePassword(String str);
        bool ValidateMail(String str);
        bool ValidateUsername(String str);
        bool ValidatePhone(String str);
        bool ValidateAge(String str);
        bool ValidatePostIndex(String str);
        bool ValidateUrl(String str);
    }
}
