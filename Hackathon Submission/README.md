# 🚗 GoRide – A Smart Ride-Sharing System

Hey! This is **GoRide** — a ride-sharing platform I built for this hackathon that’s kinda like a mini-Uber, but coded with design love, system thinking, and just the right amount of caffeine ☕.

This project is really close to me — I’ve already built a MERN stack Uber clone before, but GoRide is my **LLD + system design edition**.  
Think of it as the backend brain behind a full ride-sharing experience 🚦

---

### 🤖 Why GoRide is Special

I’ve tried to bring structure, scalability, and sanity into this system:

- ✅ Follows **SOLID principles** — clean, readable, and extensible code
- ✅ Uses key **design patterns** like Strategy, Decorator, Facade, Adapter, Observer, and more
- ✅ Designed around **modular components**: Rider, Driver, Vehicle, RideManager, Pricing, etc.
- ✅ Supports real-world features like **surge pricing**, **carpooling discounts**, and **3rd-party integrations**
- ✅ Plug-and-play logic — whether you want to change pricing rules or driver-matching strategy, you don’t have to break anything else

---

### 😅 Some fun facts

- Surge pricing kicks in faster than my brain during 9 AM lectures
- Ride cancellation not implemented, because GoRide drivers don’t ghost you 😉
- Carpool discounts because… students need to save, okay?

---
6



Hope you enjoy reviewing it as much as I enjoyed building (and re-building) it during sleepless nights! 🙌

---

## 🧠 Why I Chose These Design Patterns

### ✅ Strategy Pattern – `IMatchingStrategy`
I didn’t want to hardcode how we match drivers. Right now, I use `NearestDriverStrategy`, but if I ever wanted to match by driver rating, vehicle condition, or hairstyle (jk), I could just plug in a new class without breaking stuff.

### ✅ Factory Pattern – `VehicleFactory`
Creating a vehicle like `Sedan`, `SUV` should be flexible. What if one day we launch “AutoRickshaw” rides? Using factory here makes it super easy to scale.

### ✅ Singleton – `RideManager`
There should be only one instance managing all rides and drivers — hence Singleton. Like Gandalf, but for cabs 😄.

### ✅ Observer Pattern – `IObserver`, `Rider`
Riders get notified about ride updates — status like `EN_ROUTE` or `COMPLETED`. I used Observer so I can plug in SMS, Email, or even a WhatsApp notification later.

### ✅ Decorator Pattern – `SurgeFareDecorator`, `RideTypeFareDecorator`
Fare calculation needed to be flexible (because prices surge faster than my deadlines). So I wrapped the base calculator with decorators to apply surge + carpool discount. Worked like magic 🔥.

### ✅ Command Pattern – `RideStatusCommand`
All ride status updates like `ASSIGNED`, `EN_ROUTE`, etc. are wrapped in command objects. Makes it easy to extend later (or undo a ride, if that ever becomes a thing 😅).

### ✅ Adapter Pattern – `RazorpayAdapter`, `TwilioAdapter`
I assumed real-world services (payment/notification) would be third-party. So I used Adapters to connect my app to their interface without rewriting logic.

### ✅ Facade Pattern – `RideFacade`
My favorite! It hides all the complexity behind one method: `bookRide()`. Handles ride matching, pricing, payment, and notification — like a butler who knows everything 🧤.

---

## 🧱 How I Applied SOLID Principles

### S – Single Responsibility Principle (SRP)
Each class has only one job:
- `Rider`, `Driver`: store user info
- `Ride`: manage a single ride
- `VehicleFactory`: create vehicles
- `RideManager`: manage all rides/drivers
- `FareDecorators`: handle pricing

### O – Open/Closed Principle (OCP)
All strategies and decorators follow OCP:
- Add new driver match logic or fare decorator without modifying existing code
- System is **open for extension**, **closed for modification**

### L – Liskov Substitution Principle (LSP)
Subclasses like `Sedan`, `SUV`, and decorators behave exactly like their base class. You can swap them in and out without issues.

### I – Interface Segregation Principle (ISP)
I split responsibilities across focused interfaces:
- `IObserver`, `IFareCalculator`, `INotificationService`, etc.

No bloated interfaces — only what’s needed.

### D – Dependency Inversion Principle (DIP)
`RideFacade` and others depend on **interfaces** like `IPaymentProcessor`, not concrete classes. I inject dependencies to keep everything flexible and testable.

---

## 🧩 Design Patterns Used

| Pattern        | Class/Component                   | Role |
|----------------|-----------------------------------|------|
| Strategy       | `IMatchingStrategy`               | Flexible driver matching |
| Factory        | `VehicleFactory`                  | Create `Sedan`, `SUV`, etc. |
| Singleton      | `RideManager`                     | Global ride control |
| Observer       | `Rider`, `IObserver`              | Rider receives ride status |
| Decorator      | `SurgeFareDecorator`, `RideTypeFareDecorator` | Dynamic pricing |
| Command        | `RideStatusCommand`               | Encapsulate status changes |
| Adapter        | `RazorpayAdapter`, `TwilioAdapter`| Integrate with 3rd party |
| Facade         | `RideFacade`                      | Simplified interface to book rides |

---

## 📦 Assumptions I Made

- **Payment** is handled via Razorpay (not coded by me).
- **Notification** is simulated via Twilio adapter — could be SMS, WhatsApp, etc.
- Drivers and Riders **must be in the same location** to match.
- **Surge is 5% extra**, **Carpool gives 20% off** (hardcoded for demo).

---

## 🧪 Test Scenarios Covered

- ✅ Ride with surge + carpool
- ✅ Ride with base fare only (private ride)
- ❌ No matching driver scenario (different location)

---

## 🤣 Funny Thoughts

- If only my real Uber app was this predictable...
- I added surge pricing because my app knows it’s raining even before I do ☔
- This app doesn’t cancel the ride when the driver says “2 mins” and ghosts me.

---

---

## 🛠️ How to Clone & Run the Project

If you want to check out GoRide locally and run the simulation, here's how you do it:

### 📦 Step 1: Clone the repo
```bash
git clone 'url coming shortly after submission date ends'
```

### ⚙️ Step 2: Compile the project
Make sure you're inside the src/ directory and compile the code using g++ or any C++ compiler:

```bash
cd GoRide

then run these commands - 
g++ src/main.cpp -o rideApp
```
(Make sure all .hpp files are accessible from your include paths, or use g++ *.cpp if needed)

### ▶️ Step 3: Run it
```bash
./GoRideApp
```
You’ll see the ride booking simulation with fare calculation, ride status updates, and output printed via notification (CLI print in this version).

### 💡 Note:

- No real Razorpay or Twilio is used. They're simulated via Adapter classes.

- This is a console-based LLD prototype — no UI or database integration. All data is in memory.

---

## 🙋‍♀️ About Me


Thanks for reading this README!  
If you have any questions, feedback, or just want to say hi — feel free to connect with me.  
(Unless it’s about removing surge pricing… that’s non-negotiable 😅)

### 📬 Connect with me:
- 💼 [LinkedIn](https://www.linkedin.com/in/sakshi-jain-805537249/)
- 💻 [GitHub](https://github.com/sakshi04-ui)


