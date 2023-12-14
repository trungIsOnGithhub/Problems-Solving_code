class CreateReservation < ActiveRecord::Migration[7.1]
  def change
    create_table :reservations do |t|
      t.string :vehicle_registration_number

      t.string :vehicle_make
      t.string :vehicle_model

      t.string :driver_id

      t.string :vehicle_type

      t.time :check_in_time
      t.string :check_in_admin
      t.time :check_out_time
      t.string :check_out_admin

      t.datetime :date_stamp

      t.string :booking_status

      t.string :ticket_number

      t.integer :duration

      t.integer :parking_charge

      t.boolean :pay_state

      t.timestamps
    end
  end
end
